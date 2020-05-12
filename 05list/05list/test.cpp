// vector 动态增长数组
// 缺陷：1、头插头删和中间插入删除时间需要挪动数据，效率低下O(N),也就是说只适合尾插。
//       2、空间不够需要增容，增容是要付出代价，有不小的性能消耗。

// list 带头双向循环的链表, 可以针对性解决vector的缺陷，也就是说vector和list是两个互补形式存在的容器 
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void test_list1()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);

	list<int> copy(lt1);//拷贝构造
	list<int> lt2;
	lt2 = lt1;

	// 只能用迭代器和范围for进行遍历
	list<int>::iterator it1 = lt1.begin();
	while (it1 != lt1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;
}

void PrintList(const list<int>& lt)//打印 注意这里是const对象
{
	list<int>::const_iterator it = lt.begin();//这里要用const_iterator去接收
	while (it != lt.end())
	{
		// *it = 1;  // 不能修改
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list2()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	list<int>::reverse_iterator rit1 = lt1.rbegin();//倒着遍历一遍
	while (rit1 != lt1.rend())
	{
		cout << *rit1 << " ";
		++rit1;
	}
	cout << endl;

	PrintList(lt1);
}

void test_list3()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.pop_back();
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.push_front(-1);
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.pop_front();
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list4()
{
	// list支持任意位置O(1)的插入删除
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	// [   )算法里面有find
	list<int>::iterator pos = find(lt1.begin(), lt1.end(), 2);//找到值为2的位置 没找到返回end
	if (pos != lt1.end())
	{
		lt1.insert(pos, 20);//在2的位置前面插入一个20
	}

	for (auto e : lt1)		//遍历一遍
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.erase(pos);//删除位置为2的数
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//vector<int>::iterator vpos = find(v.begin(), v.end(), 2);
	//if (vpos != v.end())
	//{
	//	cout << "找到了" << endl;
	//}
}

void test_list5()//链表迭代器失效的问题
{
	// list支持任意位置O(1)的插入删除
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_back(5);
	lt1.push_back(6);
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>::iterator it1 = lt1.begin();
	/*while (it1 != lt1.end())//方法一 可以解决所有的问题
	{
	if (*it1 % 2 == 0)
	{
	it1 = lt1.erase(it1);//如果删除了 erase返回删除的下一个位置
	}
	else
	{
	++it1;
	}
	}*/

	while (it1 != lt1.end())//方法二
	{
		if (*it1 % 2 == 0)
		{
			lt1.erase(it1++);
		}
		else
		{
			it1++;
		}
	}

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
	//vector和list的erase都会失效
	// vector insest 迭代器会失效 (增容)
	// list   insert迭代器不会失效
}

#include "List.h"

int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	//test_list4();
	//test_list5();

	//hdzc::test_list1();
	//hdzc::test_list2();
	hdzc::test_list3();

	return 0;
}