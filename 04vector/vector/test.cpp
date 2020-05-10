
//
//void test_vector1()
//{
//	vector<int> v1;//无参构造
//	vector<int> v2(10, 5);//给10个值 初始化成5
//	vector<int> v3(v2.begin(), v2.end());
//	vector<int> v4(v3);//拷贝构造
//	v1 = v4;
//
//}
//
//
//void test_vector2()//正向迭代器
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	 //v1.pop_back();
//	//3种遍历方式
//	//1.像数组一样去使用
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//
//	}
//	cout << endl;
//	//2.迭代器
//	//vector<int>::iterator it = v1.begin();
//	//while (it != v1.end())
//	//{
//	//	*it *= 2;
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	//cout << endl;
//	////3.范围for进行遍历
//	//for (auto& e : v1)
//	//{
//	//	e *= 2;
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//
//}
//
//void test_vector3()//反向迭代器
//
//{
//
//	vector<int> v2;
//	v2.push_back(1);
//	v2.push_back(2);
//	v2.push_back(3);
//	v2.push_back(4);
//	
//	vector<int>::reverse_iterator rit = v2.rbegin();
//	while (rit != v2.rend())
//	{
//		*rit *= 2;
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}
//void Print(const vector<int>& v)//const版本为只读版本 可以用在打印中 是不可以修改的
//{
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//void test_vector4()//增容 vs下是1.5的增容 g++是2倍增容
//
//{
//	size_t sz;
//	std::vector<int> foo;
//	sz = foo.capacity();
//	std::cout << "making foo grow:\n";
//	for (int i = 0; i<100; ++i) {
//		foo.push_back(i);
//		if (sz != foo.capacity()) {
//			sz = foo.capacity();
//			std::cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//
//void test_vector5() //vector的增删查改
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.insert(v1.begin(), 0);//begin()表示第一个位置，begin()+1表示第二位置 后面表示要插入的值
//	v1.erase(v1.begin());    //删除某个位置的值 O(N)
//	//sort(v1.begin(), v1.end());//排序 里面给一个迭代区间
//	auto/*vector<int>::iterator*/ pos1 = find(v1.begin(), v1.end(), 3);//找到一个数 并在他的前面插入值
//	if (pos1 != v1.end())
//	{
//		v1.insert(pos1, 30);
//	}																	 
//	//范围for进行遍历
//	for (auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
////迭代器失效问题
//int main()
//{
//	////遍历一下迭代器
//	//vector<int> v = { 1,2,3,4 };
//	//v.reserve(5);
//	//vector<int>::iterator it = v.begin();
//	////v.reserve(5);
//	////迭代器失效是因为reserve使it失效了 解决方法：将reserve放在it之前
//	////会影响迭代器失效的操作
//	////reserve/resize
//	////insert/push_back/erase 能增容 开空间的都不可以
//	//while (it != v.end())
//	//{
//	//	cout << *it << " ";
//
//	//}
//	//cout << endl;
//	//删除容器中所有的偶数
//	vector<int> v = { 1,2,3,4 };
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//		{
//			it = v.erase(it);//vs删除it以后 it失效了 这里PJ STL在这里进行了检查
//		}
//		else
//		{
//			++it;
//		}
//	
//
//	}
//	cout << endl;
//	for (auto e : v)
//	{
//		cout << e << " ";
//
//	}
//	cout << endl;
//
//
//}
//
//
////int main()
////{
////
////	//test_vector1();
////	//test_vector2();
////	//test_vector3();
////	//test_vector4();
////	//test_vector5();
////	return 0;
////}
//
//
//
//
//
//
//




#include"vector.h"
int main()
{
	hdzc::test_vector1();
	hdzc::test_vector2();
	hdzc::test_vector3();
	hdzc::test_vector4();

	return 0;
}