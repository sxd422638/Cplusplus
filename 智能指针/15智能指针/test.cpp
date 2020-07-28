#include<iostream>
using namespace std;

#include"SmartPtr.h"

int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("��0����");

	return a / b;
}

void f1()
{
	/*int* p1 = new int;
	int* p2 = new int;
	int* p3 = new int*/;

	/*int* p = new int;
	try
	{
	cout << div() << endl;
	}
	catch (...)
	{
	delete p;
	throw;
	}
	delete p;*/

SmartPtr<int> sp1(new int);
*sp1 = 10;

SmartPtr<pair<int, int>> sp2(new pair<int, int>);
sp2->first = 20;
sp2->second = 30;

cout << div() << endl;
}

//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

// 
int x1()
{
	int* p1 = new int;
	int* p2 = p1;

	//hdzc::auto_ptr<int> ap1(new int);
	//hdzc::auto_ptr<int> ap2 = ap1;
	// *ap1 = 1; ���ձ���

	//hdzc::unique_ptr<int> up1(new int);
	//bit::unique_ptr<int> up2(up1);

	hdzc::shared_ptr<int> sp1(new int);
	hdzc::shared_ptr<int> sp2(sp1);

	hdzc::shared_ptr<int> sp3(new int);
	hdzc::shared_ptr<int> sp4(sp3);
	hdzc::shared_ptr<int> sp5(sp3);

	sp1 = sp4;


	return 0;
}

// shared_ptr�Ŀ�����ֵʱ�̰߳�ȫ����
// shared_ptr�Ƿ����̰߳�ȫ�� -�� ע�����������shared_ptr���󿽱�������++/--���ü����Ƿ��ǰ�ȫ�ģ����ʵ�����ǰ�ȫ�ġ�
#include<thread>

int x2()
{
	hdzc::shared_ptr<int> sp(new int);
	cout << sp.use_count() << endl;
	int n = 10000;

	std::thread t1([&]() {
		for (int i = 0; i < n; ++i)
		{
			hdzc::shared_ptr<int> sp1(sp);
		}
	});

	hdzc::thread t2([&]() {
		for (int i = 0; i < n; ++i)
		{
			hdzc::shared_ptr<int> sp2(sp);
		}
	});

	t1.join();
	t2.join();

	cout << sp.use_count() << endl;

	return 0;
}

struct ListNode
{
	int val;
	//ListNode* _next;
	//ListNode* _prev;
	//hdzc::shared_ptr<ListNode> _spnext;
	//hdzc::shared_ptr<ListNode> _spprev;

	hdzc::weak_ptr<ListNode> _spnext;
	hdzc::weak_ptr<ListNode> _spprev;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

int main()
{
	/*ListNode* n1 = new ListNode;
	ListNode* n2 = new ListNode;

	n1->_next = n2;
	n2->_prev = n1;

	delete n1;
	delete n2;*/

	hdzc::shared_ptr<ListNode> spn1(new ListNode);
	hdzc::shared_ptr<ListNode> spn2(new ListNode);

	cout << spn1.use_count() << endl;
	cout << spn2.use_count() << endl;

	// ѭ������
	spn1->_spnext = spn2; // �����ʽ��ʹ��weak_ptr�����������ü���
	spn2->_spprev = spn1;

	cout << spn1.use_count() << endl;
	cout << spn2.use_count() << endl;

	return 0;
}