#include<iostream>
#include<string>
#include<assert.h>
using namespace std;


//int main()
//{
////	string s1;		//�޲ι���
////	string s2("hello world");//���ι���
////	string s3(s2);	//��������
////	s1 = s3;		//��ֵ operator = 
////	cout << s1 << endl;
////	cout << s2 << endl;
////	cout << s3 << endl;
//
//	//string s1;		
//	//string s2("hello world");
//	//cout << s1.size() << endl;
//	//cout << s2.size() << endl;
//
//	//cout << s1.length() << endl;
//	//cout << s2.length() << endl;
//
//	//cout << s1.capacity() << endl;
//	//cout << s2.capacity() << endl;
//
//	//cout << s1.empty() << endl;
//	//cout << s2.empty() << endl;
//
//	//s1.clear();
//	//s2.clear();
//
//	//cout << s1.size() << endl;
//	//cout << s2.size() << endl;
//	//s2.resize(5);
//	//cout << s2 << endl;
//
//
	//string s;
	////s.reserve(1000);//ʹ��ǰ������֪����Ҫ���ٿռ䣬���ǿ���ʡȥ���ݵĿ���
	//size_t sz = s.capacity();
	//cout << "making s grow:\n";
	////string ������һ��ȱ�㣬�������ݣ��ռ䲻����Ҫ���ݣ����������������ĵ�
	////s.resize(1000); ->s[i] = 'c';
	//for (int i = 0; i < 100; ++i)
	//{
	//	s.push_back('c');
	//	//s[i] = 'c';
	//	if (sz != s.capacity())
	//	{
	//		sz = s.capacity();
	//		cout << "capacity changed: " << sz << '\n';
	//	}
	//}
////3.string��ı�������
//	//ת��������
//	//string s("12345");
//	//int value = 0;
//	////����s �����ַ�ʽ��1.size+[]
//	//for (size_t i = 0; i < s.size(); ++i)
//	//{
//	//	value *= 10;
//	//	value += (s[i] - '0') ;
//
//	//}
//	//cout << value << endl;
//
//
////4.sting�������޸Ĳ���
//	//string s1("hello ");
//	//string s2("world");
//	//s1 += ' ';
//	//s1 += "world";
//	//s1 += s2;
//	//cout << s1 << endl;
//	string file1("string.c.doc.txt");
//	string file2("string.c.doc.txt");
//	size_t pos1 = file1.find('.');���ַ���posλ�ÿ�ʼ�������ַ�c�����ظ��ַ����ַ����е�λ��
//	size_t pos2 = file1.rfind('.');���ַ���posλ�ÿ�ʼ��ǰ���ַ�c�����ظ��ַ����ַ����е�λ��
//	cout << file1.substr(pos1) << endl;
//	cout << file1.substr(pos2) << endl;
//
//
////ȡ��ur1������
//	string url1("http://www.cplusplus.com/reference/string/string/find/");
//	string url2("http://www.baidu.com/reference/string/string/find/");
//	string url3("http://www.tengxun.com/reference/string/string/find/");
//
//
//	size_t urlpos1 = url1.find("://");
//	urlpos1 += 3;
//	size_t urlend1 = url1.find('/', urlpos1);
//	cout << url1.substr(urlpos1, urlend1 - urlpos1) << endl;
//
//	size_t urlpos2 = url2.find("://");
//	urlpos2 += 3;
//	size_t urlend2 = url2.find('/', urlpos2);
//	cout << url2.substr(urlpos2, urlend2 - urlpos2) << endl;
//
//	size_t urlpos3 = url3.find("://");
//	urlpos3 += 3;
//	size_t urlend3 = url3.find('/', urlpos3);
//	cout << url3.substr(urlpos3, urlend3 - urlpos3) << endl;
//
//
	/*6.string��ʹ��
		1.����/����
		2.��->operator+= /insert
		3.ɾ->earse
		4.��->find/rfind
		5.��->operator[] 
		6.����->size() + operator[]  �˽����������  ��Χfor
		7.������� cin>>  getline(�������ַ��������ո�ʱ����)  cout<<
		8.���������ݹ��� -> VS����1.5����  g++����2����  reserve+resize
		9.c_str()�᷵�ض�����ָ���ַ������ָ��
	  10.������ > < == �ıȽ� ��ascll��ȥ�Ƚ�*/
//
//
//
//
//	return 0;
//
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	string str;
//	//cin >> str; cin�����ո���߻����������ֵ�ͽ�����
//	getline(cin, str);
//	size_t pos = str.rfind(' ');
//	cout << str.size() - pos - 1 << endl;
//
//	/*int i, j, k;
//	cin >> i >> j >> k;
//	cout << i << endl;
//	cout << j << endl;
//	cout << k << endl;*/
//
//	return 0;
//}

//#include <string>
//
//// string��Ƶù��ڸ��ӣ��ӿ�̫�࣬ѧϰ�ɳ�̫�ߡ�
//int main()
//{
//	string s1;
//	s1 += 'h';
//	s1 += "ello";
//	cout << s1 << endl;
//
//	// ���龡������������Ϊ����ʱ�临�Ӷ�ΪO(N)
//	s1.insert(0, "world");
//	s1.insert(0, " ");
//	s1.insert(6, " ");
//	cout << s1 << endl;
//
//	/*s1.erase(s1.begin());
//	cout << s1 << endl;
//	s1.erase(s1.begin()+5);
//	cout << s1 << endl;*/
//	//s1.erase();  // ->s1.clear();
//
//	//  ���龡������������Ϊ����ʱ�临�Ӷ�ΪO(N)
//	s1.erase(5, 3);
//	cout << s1 << endl;
//
//	return 0;
//}


//#include <string>
//
//// string��Ƶù��ڸ��ӣ��ӿ�̫��
//int main()
//{
///*	string s1("hello wrold");
//	size_t pos = s1.find('x');
//	if (pos != string::npos)
//	{
//		cout << pos << endl;
//	}
//	else
//	{
//		cout << "û���ҵ�" << endl;
//	}*/
//
//	string s1("hello world");
//	string s2("hello world");
//
//	 ����ʹ��+=
//	// string operator+ (const string& lhs, const string& rhs);
//	string s3 = s1 + s2;
//	s1 + "world";
//	// "world" + s1;
//
//	// string& operator+= (const string& str);
//	//string s3 = s1;
//	//s3 += s2;
//
//	// ��strcmp�ȽϹ���һ��, ���ַ���ASCII ��ȥ�Ƚ�
//	//cout << (s1 < s3) << endl;
//	//cout << (s1 == s3) << endl;
//
//	// ��Χfor�ı����������STL�е��������������������ַ�ʽ����
//	// д�������
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

// ��ǳ����
//namespace hdzc
//{ 
//	// �ַ�����
//	// ʵ��һ���򵥵�string��
//	class string
//	{
//	public:
//	/*	string()
//		{}
//
//		string(const char* str)
//		{}*/
//
//		//string(char* str = nullptr) // ���ﲻ�ܸ�nullptr��strlen(str)�ͱ�����
//		string(char* str = "") // �����һ��ȱʡֵ
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}
//		// ǳ�������ࣺ��Date��������Ĭ�����ɿ��������operator=���ǳ�����Ϳ��Ը㶨
//		// ������ࣺ��string�������Լ�ʵ�����
//		// string copy(s1)
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		// copy = s1
//		// s1 = s1
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//
//			return *this;
//		}
//
//		~string()
//		{
//			//printf("%p\n",_str);
//
//			delete[] _str;
//			_str = nullptr;
//		}
//
		/*char& operator[](size_t pos)
		{
			return _str[pos];
		}*/
//
//		const char& operator[](size_t pos) const
//		{
//			return _str[pos];
//		}
//
//		size_t size() const
//		{
//			return strlen(_str);
//		}
//
//	private:
//		char* _str;
//	};
//
//	ostream& operator<<(ostream& out, const string& s)
//	{
//		for (size_t i = 0; i < s.size(); ++i)
//		{
//			out << s[i];
//		}
//
//		return out;
//	}
//}
//
//int main()
//{
//	hdzc::string s1("world");
//	hdzc::string s2("hello");
//	s2[0] = 'x';
//
//	cout << sizeof(s1) << endl;
//	cout << sizeof(s2) << endl;
//
//	hdzc::string copy(s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << copy << endl;
//
//	copy = s1;
//	s1 = s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << copy << endl;
//
//	return 0;
//}


#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
using namespace std;


//7. ��ɾ��ĵ�string��ģ��ʵ��
namespace hdzc
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")// ���캯�� ʵ�ʵ��и���һ���ַ���
			:_size(strlen(str))   //�����ȼ�����ַ����Ĵ�С
		{
			_capacity = _size;   
			_str = new char[_capacity + 1];//���ռ��ʱ����һ��λ�ø�\0
			strcpy(_str, str); //����
		}

		~string() //����
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		// s1(s2)
		string(const string& s) //��������
		{
			// +1�ǿ��ռ�ʱ��Զ���ָ�\0�࿪һ��
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size; // size������� 
			_capacity = s._size;

			/*_str = new char[s._capacity + 1]; //���ַ�ʽ������ 
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;*/
		}

		// s1 = s2
		string& operator= (const string& s) //operator ��ֵ
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[s._size + 1]; //��s1�Ŀռ俪�ɺ�s2һ����� ��/0�࿪һ���ռ�
				strcpy(_str, s._str);         //����
				_size = s._size;
				_capacity = s._size;
			}

			return *this;
		}

		size_t size() const   
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t pos)//��������string������һ��ȥʹ�� 
		{
			assert(pos < _size);

			return _str[pos]; //���ص��ǵ�ǰ��λ��
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		void reserve(size_t n) //���ݽӿ� ��������push��appendʹ��
		{
			if (n > _capacity)
			{
				char* newstr = new char[n + 1]; //�ռ�Ԥ��һ��\0��λ�� ��Ϊ��Ҫ����Ч�ַ��Ŀռ�
				strcpy(newstr, _str); //����
				delete[] _str;//�ɿռ��ͷ�
				_str = newstr;//�ɿռ�ָ���¿ռ�
				_capacity = n;//��capacity���ӵ�n��ô��
			}
		}

		void resize(size_t n, char ch = '\0') 
		{
			if (n < _size) // n < size ��ʱ���൱��ɾ������
			{
				_size = n; //��size���n
				_str[_size] = '\0'; //���һ��λ�ø�\0
			}
			else // n > size��ʱ���������
			{
				// ����ռ䲻��������
				if (n > _capacity)
					reserve(n);

				for (size_t i = _size; i < n; ++i)//�ռ��㹻��ʱ��ʼ������
				{
					_str[i] = ch;
				}
					_size = n;
					_str[_size] = '\0';		//size�����һ��Ҫ��\0			
			}
		}

		// s1.push_back('x'); // ����ֻ����һ���ַ� ������2��һ���ǹ���
		void push_back(char ch)   //���һ���ַ�
		{
			// ����
			if (_size == _capacity)
			{
				if (_capacity == 0)
				{
					reserve(2);
				}
				else
				{
					reserve(_capacity * 2);
				}
			}

			_str[_size] = ch;//_size��ʾ���һ���ַ�����һ��λ�� ����һ��ch
			++_size;
			_str[_size] = '\0'; // ++_size �ں���Ҫ���һ��/0
		}

		// s1.append("xxxxxxxxxx");
		void append(const char* str) //��Ӷ���ַ�
		{
			size_t len = strlen(str);	//��ȥ��һ�²�����ַ��������Ƕ���
			if (_size + len > _capacity)//����ԭ�еĳ��� �� ��Ҫ����ĳ��� �������ʵ�ʵĿռ����� �ͽ�������
				reserve(_size + len);	//����

			strcpy(_str + _size, str);
			_size += len;
		}

		// s1 += 'x'
		string& operator+=(char ch)
		{
			this->push_back(ch);
			return *this;
		}

		// s1 += "xxxxx"
		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}

		string& insert(size_t pos, char ch) //��posǰһ��λ�ý��в���һ���ַ� 
		{
			assert(pos < _size);    //Ҫ��size�ķ�Χ֮�ڽ��в���
			if (_size == _capacity) //�����ַ���������
			{
				reserve(_capacity * 2);//���˽��п��ռ�
			}

			size_t end = _size;      //����Ų������Ҫ�������ǰ��ʼŲ��
			while (end >= pos)
			{
				_str[end + 1] = _str[end]; //ǰһ����ֵ����һ��
				--end;             //������ǰ��
			}

			_str[pos] = ch; // ��ʼ���ַ�
			++_size;         //�����Ϊ��������������Ҫ++size

			return *this;
		}

		string& insert(size_t pos, const char* str)//��posǰһ��λ�ý��в����ַ���
		{
			assert(pos < _size);					//��size��Χ�ڽ��в���
			size_t len = strlen(str);              //����һ���ַ���str�ĳ���
			if (_size + len > _capacity)           //�ռ䲻��Ҫ����
			{
				reserve(_size + len);
			}

			size_t end = _size;                       //�����ʼ��ǰŲ������
			while (end >= pos)
			{
				_str[end + len] = _str[end];          //һ�������Ų��len���ȵ�����
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		void erase(size_t pos, size_t len = npos)//
		{
			assert(pos < _size);

			if (_size - pos <= len)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		size_t find(char ch, size_t pos = 0)//�ҵ����ַ�
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
					return i;
			}

			return npos;
		}

		size_t find(const char* str, size_t pos = 0)//��һ���ַ���
		{
			const char* p = strstr(_str + pos, str);
			if (p == nullptr)
				return npos;
			else
				return p - _str;
		}

		// s1 < s2
		// ʵ���������������ıȽϸ���ʵ��
		bool operator<(const string& s)
		{
			return strcmp(_str, s._str) < 0;//�Ƚϵ�ǰ�ַ���ASCLL��
		}

		bool operator==(const string& s)
		{
			return strcmp(_str, s._str) == 0;//�Ƚϵ�ǰ�ַ���ASCLL��
		}

		bool operator<=(const string& s)
		{
			return *this < s || *this == s;//�Ƚϵ�ǰ�ַ���ASCLL��
		}

		bool operator>(const string& s)
		{
			return !(*this <= s);//�Ƚϵ�ǰ�ַ���ASCLL��
		}

		bool operator>=(const string& s)
		{
			return !(*this < s);
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};

	size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}

		return out;
	}

	istream& operator >> (istream& in, string& s)
	{
		while (1)
		{
			char ch = in.get();
			if (ch == ' ' || ch == '\n')
				break;
			else
				s += ch;
		}

		return in;
	}
}

void test_string1()
{
	hdzc::string s1("hello");
	s1.push_back('x');
	s1.push_back('y');
	s1.append("world");
	s1 += '!';
	s1 += "hello world";
	cout << s1 << endl;

	// ����+��д
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
		cout << s1[i] << " ";
	}
	cout << endl;

	// ����+��д
	hdzc::string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		*it1 -= 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	// ����+��д  ��Χfor���е�����֧�ֵģ�����ᱻ������ת���ɵ��������� 
	for (auto& ch : s1) //��Χfor����Ҫ֧�ֵ������������ſ���ʹ��
	{
		ch += 1; // ���԰�ch���Ϊ*it1
		cout << ch << " ";
	}
	cout << endl;

	hdzc::string s2("hello");
	s2 += 'x';
	s2.resize(3);
	s2.resize(7, 'x');
	s2.resize(15, 'x');
}

void test_string2()
{
	hdzc::string s1("hello");
	s1.insert(2, 'e');
	cout << s1 << endl;

	s1.insert(2, "world");
	cout << s1 << endl;

	hdzc::string s2("hello world wrold");
	cout << s2 << endl;
	s2.erase(5, 6);
	cout << s2 << endl;

	//s2.erase(5);
	s2.erase(5, 10);
	cout << s2 << endl;

	hdzc::string s;
	cin >> s;
	cout << s << endl;
}






























































