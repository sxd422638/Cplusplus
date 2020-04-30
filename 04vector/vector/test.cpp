#include<iostream>
#include<vector>
using namespace std;

void test_vector1()
{
	vector<int> v1;//�޲ι���
	vector<int> v2(10, 5);//��10��ֵ ��ʼ����5
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v3);//��������
	v1 = v4;

}


void test_vector2()//���������
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	//3�ֱ�����ʽ
	//1.������һ��ȥʹ��
	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";

	}
	cout << endl;
	//2.������
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		*it *= 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//3.��Χfor���б���
	for (auto& e : v1)
	{
		e *= 2;
		cout << e << " ";
	}
	cout << endl;


}

void test_vector3()//���������

{

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend())
	{
		*rit *= 2;
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
void Print(const vector<int>& v)//const�汾Ϊֻ���汾 �������ڴ�ӡ�� �ǲ������޸ĵ�
{
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_vector4()//���� vs����1.5������

{
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i<100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}





int main()
{

	//test_vector1();
	//test_vector2();
	//test_vector3();
	test_vector4();
	return 0;
}