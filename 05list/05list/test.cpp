// vector ��̬��������
// ȱ�ݣ�1��ͷ��ͷɾ���м����ɾ��ʱ����ҪŲ�����ݣ�Ч�ʵ���O(N),Ҳ����˵ֻ�ʺ�β�塣
//       2���ռ䲻����Ҫ���ݣ�������Ҫ�������ۣ��в�С���������ġ�

// list ��ͷ˫��ѭ��������, ��������Խ��vector��ȱ�ݣ�Ҳ����˵vector��list������������ʽ���ڵ����� 
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

	list<int> copy(lt1);//��������
	list<int> lt2;
	lt2 = lt1;

	// ֻ���õ������ͷ�Χfor���б���
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

void PrintList(const list<int>& lt)//��ӡ ע��������const����
{
	list<int>::const_iterator it = lt.begin();//����Ҫ��const_iteratorȥ����
	while (it != lt.end())
	{
		// *it = 1;  // �����޸�
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
	list<int>::reverse_iterator rit1 = lt1.rbegin();//���ű���һ��
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
	// list֧������λ��O(1)�Ĳ���ɾ��
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

	// [   )�㷨������find
	list<int>::iterator pos = find(lt1.begin(), lt1.end(), 2);//�ҵ�ֵΪ2��λ�� û�ҵ�����end
	if (pos != lt1.end())
	{
		lt1.insert(pos, 20);//��2��λ��ǰ�����һ��20
	}

	for (auto e : lt1)		//����һ��
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.erase(pos);//ɾ��λ��Ϊ2����
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
	//	cout << "�ҵ���" << endl;
	//}
}

void test_list5()//���������ʧЧ������
{
	// list֧������λ��O(1)�Ĳ���ɾ��
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
	/*while (it1 != lt1.end())//����һ ���Խ�����е�����
	{
	if (*it1 % 2 == 0)
	{
	it1 = lt1.erase(it1);//���ɾ���� erase����ɾ������һ��λ��
	}
	else
	{
	++it1;
	}
	}*/

	while (it1 != lt1.end())//������
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
	//vector��list��erase����ʧЧ
	// vector insest ��������ʧЧ (����)
	// list   insert����������ʧЧ
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