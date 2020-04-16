#include<iostream>
#include<string>
using namespace std;


//int main()
//{
////	string s1;		//无参构造
////	string s2("hello world");//带参构造
////	string s3(s2);	//拷贝构造
////	s1 = s3;		//赋值 operator = 
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
//	//string s;
//	////s.reserve(1000);//使用前提是我知道需要多少空间，这是可以省去增容的开销
//	//size_t sz = s.capacity();
//	//cout << "making s grow:\n";
//	////string 的其中一个缺点，插入数据，空间不够需要增容，增容是有性能消耗的
//	////s.resize(1000); ->s[i] = 'c';
//	//for (int i = 0; i < 100; ++i)
//	//{
//	//	s.push_back('c');
//	//	//s[i] = 'c';
//	//	if (sz != s.capacity())
//	//	{
//	//		sz = s.capacity();
//	//		cout << "capacity changed: " << sz << '\n';
//	//	}
//	//}
////3.string类的遍历操作
//	//转换成整形
//	//string s("12345");
//	//int value = 0;
//	////遍历s 有两种方式：1.size+[]
//	//for (size_t i = 0; i < s.size(); ++i)
//	//{
//	//	value *= 10;
//	//	value += (s[i] - '0') ;
//
//	//}
//	//cout << value << endl;
//
//
////4.sting类对象的修改操作
//	//string s1("hello ");
//	//string s2("world");
//	//s1 += ' ';
//	//s1 += "world";
//	//s1 += s2;
//	//cout << s1 << endl;
//	string file1("string.c.doc.txt");
//	string file2("string.c.doc.txt");
//	size_t pos1 = file1.find('.');
//	size_t pos2 = file1.rfind('.');
//	cout << file1.substr(pos1) << endl;
//	cout << file1.substr(pos2) << endl;
//
//
////取出ur1的域名
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
//	//6.string的使用
//	//	1.构造/拷贝
//	//	2.增->operator+= /insert
//	//	3.删->earse
//	//	4.查->find/rfind
//	//	5.改->operator[] 
//	//	6.遍历->size() + operator[]  了解迭代器遍历  范围for
//	//	7.输入输出 cin>>  getline(当输入字符串包含空格时用它)  cout<<
//	//	8.容量，增容规则 -> VS基本1.5倍增  g++基本2倍增  reserve+resize
//	//	9.c_str()会返回对象中指向字符数组的指针
//	//  10.重载了 > < == 的比较 按ascll码去比较
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
//	//cin >> str; cin遇到空格或者换行这次输入值就结束了
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
//// string设计得过于复杂，接口太多，学习成长太高。
//int main()
//{
//	string s1;
//	s1 += 'h';
//	s1 += "ello";
//	cout << s1 << endl;
//
//	// 建议尽量不用它，因为他的时间复杂度为O(N)
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
//	//  建议尽量不用它，因为他的时间复杂度为O(N)
//	s1.erase(5, 3);
//	cout << s1 << endl;
//
//	return 0;
//}


//#include <string>
//
//// string设计得过于复杂，接口太多
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
//		cout << "没有找到" << endl;
//	}*/
//
//	string s1("hello world");
//	string s2("hello world");
//
//	 尽量使用+=
//	// string operator+ (const string& lhs, const string& rhs);
//	string s3 = s1 + s2;
//	s1 + "world";
//	// "world" + s1;
//
//	// string& operator+= (const string& str);
//	//string s3 = s1;
//	//s3 += s2;
//
//	// 跟strcmp比较规则一样, 按字符的ASCII 码去比较
//	//cout << (s1 < s3) << endl;
//	//cout << (s1 == s3) << endl;
//
//	// 范围for的遍历，数组和STL中的所有容器都可以用这种方式遍历
//	// 写起来简洁
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

// 深浅拷贝
//namespace bit
//{ 
//	// 字符数组
//	// 实现一个简单的string类
//	class string
//	{
//	public:
//	/*	string()
//		{}
//
//		string(const char* str)
//		{}*/
//
//		//string(char* str = nullptr) // 这里不能给nullptr，strlen(str)就崩溃了
//		string(char* str = "")
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}
//		// 浅拷贝的类：如Date，编译器默认生成拷贝构造和operator=完成浅拷贝就可以搞定
//		// 深拷贝的类：如string，必须自己实现深拷贝
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
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
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
//	bit::string s1("world");
//	bit::string s2("hello");
//	s2[0] = 'x';
//
//	cout << sizeof(s1) << endl;
//	cout << sizeof(s2) << endl;
//
//	bit::string copy(s2);
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
#include <assert.h>
using namespace std;


//7. 增删查改的string类模拟实现
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

		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		// s1(s2)
		string(const string& s)
		{
			// +1是开空间时永远保持给\0多开一个
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._size;

			/*_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;*/
		}

		// s1 = s2
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[s._size + 1];
				strcpy(_str, s._str);
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

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* newstr = new char[n + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;

				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size) // 删除数据
			{
				_size = n;
				_str[_size] = '\0';
			}
			else // 插入数据
			{
				// 空间不够先增容
				if (n > _capacity)
					reserve(n);

				for (size_t i = _size; i < n; ++i)
					_str[i] = ch;
				_size = n;
				_str[_size] = '\0';
			}
		}

		// s1.push_back('x');
		void push_back(char ch)
		{
			// 增容
			if (_size == _capacity)
				reserve(_capacity * 2);

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		// s1.append("xxxxxxxxxx");
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_size + len);

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

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos, size_t len = npos);
		size_t find(char ch);
		size_t find(const char* str);

		// s1 < s2
		
		bool operator<(const string& s);
		bool operator==(const string& s);

		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator!=(const string& s);

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

	istream& operator >> (istream& in, string& s);

}

int main()
{
	hdzc::string s1("hello");
	s1.push_back('x');
	s1.push_back('y');
	s1.append("world");
	s1 += '!';
	s1 += "hello world";
	cout << s1 << endl;

	// 遍历+读写
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
		cout << s1[i] << " ";
	}
	cout << endl;

	// 遍历+读写
	hdzc::string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		*it1 -= 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	// 遍历+读写  范围for是有迭代器支持的，这里会被编译器转换成迭代器遍历
	for (auto& ch : s1)
	{
		ch += 1;
		cout << ch << " ";
	}
	cout << endl;

	hdzc::string s2("hello");
	s2 += 'x';
	s2.resize(3);
	s2.resize(7, 'x');
	s2.resize(15, 'x');

	return 0;
}































































