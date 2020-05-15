#pragma once
namespace hdzc
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* _prev;
		__list_node<T>* _next;
					  T _data;

		__list_node(const T& data = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(data)
		{}
	};

	template<class T, class Ref, class Ptr>//3个模板参数 引用 指针
	struct __list_iterator
	{
		typedef __list_iterator<T, Ref, Ptr> Self;//Self是自己定义的名称
		typedef __list_node<T> node;
		node* _node;

		__list_iterator(node* node)//结点的指针
			:_node(node)
		{}

		// 链表的迭代的核心还是节点的指针
		// 但是封装在类，可以通过运算符去控制++ * 等行为
		//T& operator*() 返回的是对象
		Ref operator*()
		{
			return _node->_data;
		}

		// T* operator->()返回的是指针
		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()//后置++
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)//前置++
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()//后置--
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)//前置--
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;//3个模板参数
		typedef __list_iterator<T, const T&, const T*>  const_iterator; // const迭代器
		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		list()//构造函数
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		// list<int> lt2(lt1)
		list(const list<int>& lt)//拷贝构造
		{
			_head = new node;//先找出头结点 并让它自己指向自己 此时没有数据
			_head->_next = _head;
			_head->_prev = _head;

			for (auto e : lt)//往lt2里面遍历lt1
				push_back(e);
		}

		// lt1 = lt3; operator=
		/*	list<T>& operator=(const list<int>& lt) //方法一
		{
		if (this != &lt)//lt1去调clear  lt相当于lt3
		{
		clear();
		for (auto e : lt)
		{
		push_back(e);
		}
		}

		return *this;
		}
		*/
		// lt1 = lt3
		list<T>& operator=(list<int> lt)//方法二  现代写法
		{
			swap(_head, lt._head);//深拷贝 交换 lt1的head和lt3的交换 出作用域后lt3进行析构

			return *this;
		}


		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				iterator next = it;
				++next;

				delete it._node;

				it = next;
			}

			_head->_next = _head;//恢复成最开始的状态
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			/*node* newnode = new node(x);
			node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), x);//因为在双向循环链表end的位置在head 所以在end前面插入即为尾插
		}

		void pop_back()//尾删 先--找到最后一个位置 再erase
		{
			erase(--end());
		}

		void push_front(const T& x)//在begin前面插入
		{
			insert(begin(), x);
		}

		void pop_front()//删除begin位置上的数
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)//在pos前的位置插入一个值 定义为newnode
		{
			node* cur = pos._node;//直接可以访问当前的node
			node* prev = cur->_prev;
			node* newnode = new node(x);

			// prev newnode cur 把3个结点连接起来
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());//不能删除头结点

			node* del = pos._node;//要删除的结点
			node* prev = del->_prev;
			node* next = del->_next;

			prev->_next = next;
			next->_prev = prev;
			delete del;

			return iterator(next);//返回删除这个地方下一个位置的迭代器 否则迭代器会失效
		}
	private:
		node* _head;
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();//遍历一遍
		while (it != lt.end())
		{
			*it *= 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	struct A
	{
		A(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}

		int _a1;
		int _a2;
	};

	void test_list2()
	{
		/*int* p1 = new int;
		cout << *p1 << endl;
		A* p2 = new A(1,2);
		cout << p2->_a1 << endl;
		cout << p2->_a2 << endl;*/

		list<A> lt;
		lt.push_back(A(1, 2));
		lt.push_back(A(10, 20));
		lt.push_back(A(100, 200));
		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << *it << " ";
			cout << it->_a1 << ":" << it->_a2 << endl;
			++it;
		}
		cout << endl;
	}

	void PrintList(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it = 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		PrintList(lt);

		lt.clear();
		PrintList(lt);
	}
}