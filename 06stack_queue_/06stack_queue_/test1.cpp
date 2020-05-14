#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

void test_stack()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	// LIFO last in first out
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void test_queue()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	// FIFO first in first out
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

// 适配器
// 模拟实现一个栈
namespace hdzc
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& x) { _con.push_back(x); }

		void pop() { _con.pop_back(); }

		T& top() { return _con.back(); }

		bool empty() { return _con.empty(); }
		size_t size()
		{
			return _con.size();
		}
	private:
		Container _con;
	};

	void test_stack()
	{
		//stack<int, vector<int>> s;
		//stack<int, list<int>> s;
		stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);

		// LIFO last in first out
		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}

	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& x) { _con.push_back(x); }
		void pop() { _con.pop_front(); }
		T& front() { return _con.front(); }
		bool empty() {
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}
	private:
		Container _con;
	};

	void test_queue()
	{
		//queue<int> q;
		queue<int, list<int>> q;
		//queue<int, vector<int>> q; 编译报错，vector不支持头删
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		// FIFO first in first out
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}

	// 结合图了解框架设计
	template<class T>
	struct __deque_iterator
	{
		T* cur;
		T* first;
		T* last;
		T** node;

		T& operator*()
		{
			return *cur;
		}

		__deque_iterator<T>& operator++()
		{
			// 1.当前buff数组还没走完，则遍历当前buff数组
			// 2.如果走完了，则找到下一个buff数组
			if (cur != last)
			{
				++cur;
			}
			else
			{
				node += 1;
				first = *node;
				last = first + N;
				cur = first;
			}
		}

		bool operator!=(const __deque_iterator<T>& it)
		{
			return cur != it.cur;
		}
	};

	template<class T>
	class deque
	{
	public:
		typedef __deque_iterator<T> iterator;
		iterator begin()
		{
			return start;
		}

		iterator end()
		{
			return finsih;
		}
		// 头尾的插入效率都不错

		// 败笔：随机访问
		T& operator[](size_t i)
		{
			// ...
		}
	private:
		iterator start;  // 指向第一个buff数组 start.cur指向buff数组中第一个数据
		iterator finsih; // 指向组以后一个buff数组 start.cur指向buff数组中最后一个数据下一个位置
	};
}

int main()
{
	//test_stack();
	//test_queue();
	hdzc::test_stack();
	hdzc::test_queue();


	return 0;
}