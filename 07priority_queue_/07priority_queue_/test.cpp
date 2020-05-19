#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;
//�ײ�ʵ���Ƕ�
void test_priority_queue()
{
	priority_queue<int> pq;//��������ȼ��� ->��� less
	//priority_queue<int ,vector<int> , greater<int>> pq; //С�����ȼ���
	pq.push(10);
	pq.push(21);
	pq.push(5);
	pq.push(30);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.top();
	}
	cout << endl;

}



#pragma once

namespace hdzc
{
	// ����������
	template<class T>
	struct less {
		bool operator()(const T& x1, const T& x2) { return x1 < x2; }
	};

	template<class T>
	struct greater {
		bool operator()(const T& x1, const T& x2) { return x1 > x2; }
	};

	// Ĭ�ϸ���С�ڵķº�����ʵ�ֵĴ��
	// ���Ĵ��ڵķº�����ʵ�ֵ�С�ѣ��������֣�д�Ĵ��е�bug
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(size_t child)//���ϵ����㷨 ����֮ǰ���Ǵ��
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0) //����=0ʱ����
			{
				/*if (com(_con[parent], _con[child]))*/
					if (_con[child] > _con[parent])//���������ϵ���
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else//���һ��ʼ��С�Ͳ��ü���������
				{
					break;
				}
			}
		}

		void AdjustDwon(size_t root)//���µ����㷨
		{
			Compare com;
			size_t parent = root;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				// ѡ������Ǹ���ֽ
				if (child + 1 < _con.size() && _con[child+1] > _con[child])
				//if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
					++child;

				// ������Ӵ��ڸ��ף��򽻻�
				if (com(_con[parent], _con[child]))
					//if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			AdjustDwon(0);
		}

		T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			_con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};

	void test_priority_queue()
	{
		//priority_queue<int> pq;
		priority_queue<int, vector<int>, hdzc::greater<int>> pq;
		pq.push(10);
		pq.push(2);
		pq.push(30);
		pq.push(21);
		pq.push(5);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;

		less<int> less_func;
		cout << less_func(1, 2) << endl;
		cout << less_func.operator()(1, 2) << endl;

	}
}

void test_deque()
{
	srand(time(0));
	vector<int> v;
	v.reserve(10000);
	for (size_t i = 0; i < 10000; ++i)
	{
		v.push_back(rand());
	}

	deque<int> dq;
	for (size_t i = 0; i < 10000; ++i)
	{
		dq.push_back(v[i]);
	}

	size_t begin1 = clock();
	sort(v.begin(), v.end());
	size_t end1 = clock();

	size_t begin2 = clock();
	sort(dq.begin(), dq.end());
	size_t end2 = clock();

	cout << end1 - begin1 << endl;
	cout << end2 - begin2 << endl;
}
// ���ȼ����еײ��ǣ� ��
void test_priority_queue()
{
	// ������ȼ��� -- ���  less
	//priority_queue<int> pq;

	// С�����ȼ��� -- С��   greater
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(10);
	pq.push(2);
	pq.push(30);
	pq.push(21);
	pq.push(5);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

bool greater_fun(int x1, int x2)
{
	return x1 > x2;
}

//�º������Ƶ���������
// > �ķº���ʱ����  < �ķº���ʱ����




int main()
{
	//test_stack();
	//test_queue();
	//bit::test_stack();
	//bit::test_queue();
	//test_deque();
	//test_priority_queue();
	//bit::test_priority_queue();

	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	greater<int> gt;
	/*sort(v.begin(), v.end(), gt);*/
	//sort(v.begin(), v.end(), greater<int>());//����һ����������Ϳ�����
	sort(v.begin(), v.end(), greater_fun);
	cout << greater_fun(1, 2) << endl;
	cout << gt(1, 2) << endl;


	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;


	return 0;
}





// ����ģ�����
// ������ģ����� -> ����   һ�㶼������ int ��unsigned int�ȵ�
// ���徲̬������
//#define N 1000
template<class T, size_t N = 10>
class Array
{
public:
	T& operator[](size_t i)
	{
		return _a[i];
	}

	size_t size()
	{
		return _size;
	}
private:
	T _a[N];
	size_t _size = 0; // ȱʡֵ
};

//int main()
//{
//	Array<int> a0;  // 10
//
//	Array<int, 100> a1;  // 100
//	//a1[0];
//	Array<int, 1000> a2;  // 1000
//
//	return 0;
//}