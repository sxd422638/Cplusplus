#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include <assert.h>
using namespace std;
//模拟实现
namespace hdzc
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;//const在*之前修饰的是指针内容 在*之后修饰的是指针本身

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		// copy(v)浅拷贝的问题
		vector(const vector<T>& v)//拷贝构造
		{
			_start = new T[v.size()];//开空间
			_finish = _start + v.size();
			_endofstorage = _start + v.size();

			memcpy(_start, v._start, sizeof(T)*v.size());//拷贝数据
		}

		// x = copy浅拷贝的问题
		vector<T>& operator=(vector<T> v)//赋值
		{
			this->swap(v);//现代写法 自己的不想要了 交换给v v出了作用域析构
			return *this;
		}

		// v1.swap(v2) 比传统的拷贝代价更小 使用成员函数
		void swap(vector<T>& v)
		{
			::swap(_start, v._start);//加域外访问符的意思是去调用全局的swap
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		iterator begin()
		{
			return _start;
		}

		const_iterator begin() const
		{
			return _start;
		}

		iterator end()
		{
			return _finish;//不是要遍历所有空间而是要遍历所有数据
		}

		const_iterator end() const
		{
			return _finish;
		}

		void reserve(size_t n)//开新的空间 拷贝数据
		{
			if (n > capacity())
			{
				size_t sz = size();//在还没有增容之前 先算好size
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, size() * sizeof(T));//将原空间的值转移到新开辟的空间中
					delete[] _start;//释放源空间
				}
				_start = tmp;
				_finish = _start + sz;//这边加的是原来的size大小
				_endofstorage = _start + n;//算上新增加的n的大小

			}
		}

		void resize(size_t n, const T& val = T())//给一个缺省值是T类型的匿名对象
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}

				while (_finish != _start + n)
				{
					*_finish = val;//不断地填入数据
					++_finish;//直到finish = start + n
				}
			}
		}

		void push_back(const T& x)
		{
			/*if (_finish == _endofstorage)
			{
			size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
			reserve(newcapacity);
			}

			*_finish = x;
			++_finish;*/

			insert(end(), x);
		}

		void pop_back()//删除数据
		{
			/*assert(_finish > _start);
			--_finish;*/
			erase(end() - 1);
		}

		void insert(iterator pos, const T& x)//在指定位置前面插入一个数据
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;//没增容之前 计算相对位置
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);

				// 增容以后pos失效了，得重置pos在新空间的位置
				pos = _start + len;//重置一下pos
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}

		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;

			return pos;//返回的位置就是pos
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}
	private:
		iterator _start;
		iterator _finish;//start + size()
		iterator _endofstorage;//相当于 start+capacity 指向存储容量的尾
		/*T* _a;
		size_t _size;
		size_t _capacity;*/
	};


	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		v.insert(v.begin() + 2, 30);
		v.insert(v.begin(), 0);
		v.insert(v.begin(), -1);
		v.insert(v.end(), 6);
		v.insert(v.begin(), -2);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		v.erase(v.begin() + 5);//删除30
		v.pop_back();
		for (auto e : v)//遍历方式
		{
			cout << e << " ";
		}
		cout << endl;
		
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		//深浅拷贝的问题
		vector<int> copy(v);//把原来的和拷贝的分别遍历一下
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> x;
		x = v;
		for (auto e : x)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int> v2;
		v2.push_back(10);
		v2.push_back(20);
		v2.push_back(30);
		v2.push_back(40);
		v2.push_back(50);

		swap(v1, v2);
	}

	void test_vector4()//vector<vector<int>> vv 二维数组vector的vector
	{
		// 10*5
		vector<vector<int>> vv;
		vv.resize(10);
		for (size_t i = 0; i < vv.size(); ++i)
		{
			vv[i].resize(5, 1);
		}

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				cout << vv[i][j] << " ";
			}
			cout << endl;
		}
	}
}
