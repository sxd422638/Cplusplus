//#include <iostream>
//using namespace std;
//
//// ����ģ��
//template<class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//
//// ģ���ػ�
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
////	// Ҫ���char*���ͽ�������Ĵ���
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
//// ��ģ��
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
////  ��ģ���ػ�  ȫ�ػ� ��ģ������в�����Ҫȷ����
//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//};
//
////  ��ģ���ػ�  ƫ�ػ�/���ػ�  ����ȫ�����ػ����ֲ�����Ҳ���ܶԲ����Ľ�һ�����ơ�
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
//	// Ϊʲô�������Ͳ���Ҫ��������<< >> �������   �������Ѿ�ʵ����������������ʵ��
//	// Ϊʲô�������Զ�ʶ�����ͣ�                   ��������
//	/*int i;
//	double d;
//	cin >> i;
//	cin >> d;
//
//	cout << i << endl;
//	cout << d << endl;*/
//
//	int n;
//	// ��ctrl + C����
//	//while (cin >> n) // istream& operator>>(int)
//	//{
//	//	cout << n << endl;
//	//}
//
//	return 0;
//}

#include <fstream>
#include <string>

// ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д�����ļ�
struct ServerInfo
{
	char _ip[32];	// ip
	int  _port;		// �˿�
};

struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}

	// �����ƶ�д  �ڴ��������ʲô����д�����̾���ʲô�� (ȱ�㣺�ļ����Ժ�������)
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

	// �ı���д  ת���ַ���д��ȥ�����ŵ㣺д��ȥ������ˣ�ȱ�㣺�Ƚ��鷳�� 
	/* ��ͳ��д����ת�ַ���д�������ַ�����ת��Ҫ�����Ͷ���  ����������л��ͷ����л�
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
		ofs << info._port << endl;   // �ײ�Ҳ������ת���ַ���д����
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_configfile.c_str());
		ifs >> info._ip;
		ifs >> info._port;          // �ײ�����ַ���ת������
	}
private:
	string _configfile; // �����ļ�
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