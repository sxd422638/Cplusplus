#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include <assert.h>
using namespace std;
//ģ��ʵ��
namespace hdzc
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;//const��*֮ǰ���ε���ָ������ ��*֮�����ε���ָ�뱾��

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		// copy(v)ǳ����������
		vector(const vector<T>& v)//��������
		{
			_start = new T[v.size()];//���ռ�
			_finish = _start + v.size();
			_endofstorage = _start + v.size();

			memcpy(_start, v._start, sizeof(T)*v.size());//��������
		}

		// x = copyǳ����������
		vector<T>& operator=(vector<T> v)//��ֵ
		{
			this->swap(v);//�ִ�д�� �Լ��Ĳ���Ҫ�� ������v v��������������
			return *this;
		}

		// v1.swap(v2) �ȴ�ͳ�Ŀ������۸�С ʹ�ó�Ա����
		void swap(vector<T>& v)
		{
			::swap(_start, v._start);//��������ʷ�����˼��ȥ����ȫ�ֵ�swap
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
			return _finish;//����Ҫ�������пռ����Ҫ������������
		}

		const_iterator end() const
		{
			return _finish;
		}

		void reserve(size_t n)//���µĿռ� ��������
		{
			if (n > capacity())
			{
				size_t sz = size();//�ڻ�û������֮ǰ �����size
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, size() * sizeof(T));//��ԭ�ռ��ֵת�Ƶ��¿��ٵĿռ���
					delete[] _start;//�ͷ�Դ�ռ�
				}
				_start = tmp;
				_finish = _start + sz;//��߼ӵ���ԭ����size��С
				_endofstorage = _start + n;//���������ӵ�n�Ĵ�С

			}
		}

		void resize(size_t n, const T& val = T())//��һ��ȱʡֵ��T���͵���������
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
					*_finish = val;//���ϵ���������
					++_finish;//ֱ��finish = start + n
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

		void pop_back()//ɾ������
		{
			/*assert(_finish > _start);
			--_finish;*/
			erase(end() - 1);
		}

		void insert(iterator pos, const T& x)//��ָ��λ��ǰ�����һ������
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;//û����֮ǰ �������λ��
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);

				// �����Ժ�posʧЧ�ˣ�������pos���¿ռ��λ��
				pos = _start + len;//����һ��pos
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

			return pos;//���ص�λ�þ���pos
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
		iterator _endofstorage;//�൱�� start+capacity ָ��洢������β
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

		v.erase(v.begin() + 5);//ɾ��30
		v.pop_back();
		for (auto e : v)//������ʽ
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
		//��ǳ����������
		vector<int> copy(v);//��ԭ���ĺͿ����ķֱ����һ��
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

	void test_vector4()//vector<vector<int>> vv ��ά����vector��vector
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
