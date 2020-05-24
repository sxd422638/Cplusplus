//#include <iostream>
//using namespace std;
//
//// 函数模板
//template<class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//
//// 模板特化
//template<>
//bool IsEqual<char*>(char*& left, char*& right)
//{
//	return strcmp(left, right) == 0;
//}
//
////int main()
////{
////	int x1 = 1, x2 = 2;
////	cout << IsEqual(x1, x2) << endl;
////
////	// 要针对char*类型进行特殊的处理
////	char* p1 = "hello";
////	char* p2 = "world";
////	if (IsEqual(p1, p2))
////		cout << p1 << endl;
////	else
////		cout << p2 << endl;
////
////	return 0;
////}
//
//// 类模板
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
////  类模板特化  全特化 类模板的所有参数都要确定化
//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//};
//
////  类模板特化  偏特化/半特化  并不全都是特化部分参数，也可能对参数的进一步限制。
//template<class T1>
//class Data<T1, double>
//{
//public:
//	Data() { cout << "Data<T1, double>" << endl; }
//private:
//};
//
//template<class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//};
//
//template<class T1, class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//private:
//};
//
////int main()
////{
////	Data<int, int> d1;
////	Data<int, char> d2;
////	Data<int, double> d3;
////	Data<char, double> d4;
////	Data<char*, double*> d5;
////	Data<int*, int*> d6;
////	Data<char&, double&> d7;
////	Data<int&, int&> d8;
////
//////	return 0;
//////}
//
//#include "Func.h"
//
//int main()
//{
//	F1(1);							// call F1(?)
//
//	cout << Add(1, 2) << endl;		// call Add<int>(?)
//	cout << Add(1.1, 2.2) << endl;	// call Add<double>(?)
//	cout << Add('a', 'b') << endl;	// call Add<double>(?)
//
//}

#include <iostream>
using namespace std;

//int main()
//{
//	// 为什么内置类型不需要我们重载<< >> 运算符？   库里面已经实现了内置类型重载实现
//	// 为什么他可以自动识别类型？                   函数重载
//	/*int i;
//	double d;
//	cin >> i;
//	cin >> d;
//
//	cout << i << endl;
//	cout << d << endl;*/
//
//	int n;
//	// 按ctrl + C结束
//	//while (cin >> n) // istream& operator>>(int)
//	//{
//	//	cout << n << endl;
//	//}
//
//	return 0;
//}

#include <fstream>
#include <string>

// 使用文件IO流用文本及二进制方式演示读写配置文件
struct ServerInfo
{
	char _ip[32];	// ip
	int  _port;		// 端口
};

struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}

	// 二进制读写  内存二进制是什么样，写到磁盘就是什么样 (缺点：文件打开以后是乱码)
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_configfile.c_str());
		ofs.write((const char*)&info, sizeof(ServerInfo));
	}

	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_configfile.c_str());
		ifs.read((char*)&info, sizeof(ServerInfo));
	}

	// 文本读写  转成字符串写出去。（优点：写出去方便读了，缺点：比较麻烦） 
	/* 传统的写法，转字符串写出，读字符串再转成要的类型对象  这个过程序列化和反序列化
	void WriteText(const ServerInfo& info)
	{
	ofstream ofs(_configfile.c_str());
	ofs.write(info._ip, strlen(info._ip));
	ofs.put('\n');
	string ipstr = to_string(info._port);
	ofs.write(ipstr.c_str(), ipstr.size());
	}

	void ReadText(ServerInfo& info)
	{
	ifstream ifs(_configfile.c_str());
	ifs.getline(info._ip, 32);
	char ipstr[10];
	ifs.getline(ipstr, 10);
	info._port = stoi(ipstr);
	}*/

	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_configfile.c_str());
		ofs << info._ip << endl;
		ofs << info._port << endl;   // 底层也是整形转成字符串写出的
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_configfile.c_str());
		ifs >> info._ip;
		ifs >> info._port;          // 底层读入字符串转成整形
	}
private:
	string _configfile; // 配置文件
};

int main()
{
	ServerInfo info;
	strcpy(info._ip, "192.168.3.1");
	info._port = 80;

	//ConfigManager cm;
	//cm.WriteBin(info);

	//ServerInfo ret;
	//cm.ReadBin(ret);
	//cout << ret._ip << endl;
	//cout << ret._port << endl;

	ConfigManager cm;
	cm.WriteText(info);

	ServerInfo ret;
	cm.ReadText(ret);
	cout << ret._ip << endl;
	cout << ret._port << endl;

	return 0;
}