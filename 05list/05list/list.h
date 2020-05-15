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

	template<class T, class Ref, class Ptr>//3��ģ����� ���� ָ��
	struct __list_iterator
	{
		typedef __list_iterator<T, Ref, Ptr> Self;//Self���Լ����������
		typedef __list_node<T> node;
		node* _node;

		__list_iterator(node* node)//����ָ��
			:_node(node)
		{}

		// ����ĵ����ĺ��Ļ��ǽڵ��ָ��
		// ���Ƿ�װ���࣬����ͨ�������ȥ����++ * ����Ϊ
		//T& operator*() ���ص��Ƕ���
		Ref operator*()
		{
			return _node->_data;
		}

		// T* operator->()���ص���ָ��
		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()//����++
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)//ǰ��++
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()//����--
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)//ǰ��--
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
		typedef __list_iterator<T, T&, T*> iterator;//3��ģ�����
		typedef __list_iterator<T, const T&, const T*>  const_iterator; // const������
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

		list()//���캯��
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		// list<int> lt2(lt1)
		list(const list<int>& lt)//��������
		{
			_head = new node;//���ҳ�ͷ��� �������Լ�ָ���Լ� ��ʱû������
			_head->_next = _head;
			_head->_prev = _head;

			for (auto e : lt)//��lt2�������lt1
				push_back(e);
		}

		// lt1 = lt3; operator=
		/*	list<T>& operator=(const list<int>& lt) //����һ
		{
		if (this != &lt)//lt1ȥ��clear  lt�൱��lt3
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
		list<T>& operator=(list<int> lt)//������  �ִ�д��
		{
			swap(_head, lt._head);//��� ���� lt1��head��lt3�Ľ��� ���������lt3��������

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

			_head->_next = _head;//�ָ����ʼ��״̬
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

			insert(end(), x);//��Ϊ��˫��ѭ������end��λ����head ������endǰ����뼴Ϊβ��
		}

		void pop_back()//βɾ ��--�ҵ����һ��λ�� ��erase
		{
			erase(--end());
		}

		void push_front(const T& x)//��beginǰ�����
		{
			insert(begin(), x);
		}

		void pop_front()//ɾ��beginλ���ϵ���
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)//��posǰ��λ�ò���һ��ֵ ����Ϊnewnode
		{
			node* cur = pos._node;//ֱ�ӿ��Է��ʵ�ǰ��node
			node* prev = cur->_prev;
			node* newnode = new node(x);

			// prev newnode cur ��3�������������
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());//����ɾ��ͷ���

			node* del = pos._node;//Ҫɾ���Ľ��
			node* prev = del->_prev;
			node* next = del->_next;

			prev->_next = next;
			next->_prev = prev;
			delete del;

			return iterator(next);//����ɾ������ط���һ��λ�õĵ����� �����������ʧЧ
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

		list<int>::iterator it = lt.begin();//����һ��
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