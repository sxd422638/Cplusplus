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

// ������
// ģ��ʵ��һ��ջ
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
		//queue<int, vector<int>> q; ���뱨��vector��֧��ͷɾ
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

	// ���ͼ�˽������
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
			// 1.��ǰbuff���黹û���꣬�������ǰbuff����
			// 2.��������ˣ����ҵ���һ��buff����
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
		// ͷβ�Ĳ���Ч�ʶ�����

		// �ܱʣ��������
		T& operator[](size_t i)
		{
			// ...
		}
	private:
		iterator start;  // ָ���һ��buff���� start.curָ��buff�����е�һ������
		iterator finsih; // ָ�����Ժ�һ��buff���� start.curָ��buff���������һ��������һ��λ��
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