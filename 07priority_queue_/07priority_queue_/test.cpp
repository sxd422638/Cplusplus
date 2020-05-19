#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;
//底层实现是堆
void test_priority_queue()
{
	priority_queue<int> pq;//大的数优先级高 ->大堆 less
	//priority_queue<int ,vector<int> , greater<int>> pq; //小的优先级高
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
	// 容器适配器
	template<class T>
	struct less {
		bool operator()(const T& x1, const T& x2) { return x1 < x2; }
	};

	template<class T>
	struct greater {
		bool operator()(const T& x1, const T& x2) { return x1 > x2; }
	};

	// 默认给的小于的仿函数，实现的大堆
	// 给的大于的仿函数，实现的小堆，这个很奇怪，写的大佬的bug
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(size_t child)//向上调整算法 调整之前就是大堆
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0) //孩子=0时结束
			{
				/*if (com(_con[parent], _con[child]))*/
					if (_con[child] > _con[parent])//将孩子往上调整
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else//如果一开始就小就不用继续调整了
				{
					break;
				}
			}
		}

		void AdjustDwon(size_t root)//向下调整算法
		{
			Compare com;
			size_t parent = root;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				// 选出大的那个孩纸
				if (child + 1 < _con.size() && _con[child+1] > _con[child])
				//if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
					++child;

				// 如果孩子大于父亲，则交换
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
// 优先级队列底层是？ 堆
void test_priority_queue()
{
	// 大的优先级高 -- 大堆  less
	//priority_queue<int> pq;

	// 小的优先级高 -- 小堆   greater
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

//仿函数控制的是升序降序
// > 的仿函数时降序  < 的仿函数时升序




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
	//sort(v.begin(), v.end(), greater<int>());//定义一个匿名对象就可以了
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





// 类型模板参数
// 非类型模板参数 -> 常量   一般都是整形 int 、unsigned int等等
// 定义静态的数组
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
	size_t _size = 0; // 缺省值
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