
//
//void test_vector1()
//{
//	vector<int> v1;//�޲ι���
//	vector<int> v2(10, 5);//��10��ֵ ��ʼ����5
//	vector<int> v3(v2.begin(), v2.end());
//	vector<int> v4(v3);//��������
//	v1 = v4;
//
//}
//
//
//void test_vector2()//���������
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	 //v1.pop_back();
//	//3�ֱ�����ʽ
//	//1.������һ��ȥʹ��
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//
//	}
//	cout << endl;
//	//2.������
//	//vector<int>::iterator it = v1.begin();
//	//while (it != v1.end())
//	//{
//	//	*it *= 2;
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	//cout << endl;
//	////3.��Χfor���б���
//	//for (auto& e : v1)
//	//{
//	//	e *= 2;
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//
//}
//
//void test_vector3()//���������
//
//{
//
//	vector<int> v2;
//	v2.push_back(1);
//	v2.push_back(2);
//	v2.push_back(3);
//	v2.push_back(4);
//	
//	vector<int>::reverse_iterator rit = v2.rbegin();
//	while (rit != v2.rend())
//	{
//		*rit *= 2;
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}
//void Print(const vector<int>& v)//const�汾Ϊֻ���汾 �������ڴ�ӡ�� �ǲ������޸ĵ�
//{
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//void test_vector4()//���� vs����1.5������ g++��2������
//
//{
//	size_t sz;
//	std::vector<int> foo;
//	sz = foo.capacity();
//	std::cout << "making foo grow:\n";
//	for (int i = 0; i<100; ++i) {
//		foo.push_back(i);
//		if (sz != foo.capacity()) {
//			sz = foo.capacity();
//			std::cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//
//void test_vector5() //vector����ɾ���
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.insert(v1.begin(), 0);//begin()��ʾ��һ��λ�ã�begin()+1��ʾ�ڶ�λ�� �����ʾҪ�����ֵ
//	v1.erase(v1.begin());    //ɾ��ĳ��λ�õ�ֵ O(N)
//	//sort(v1.begin(), v1.end());//���� �����һ����������
//	auto/*vector<int>::iterator*/ pos1 = find(v1.begin(), v1.end(), 3);//�ҵ�һ���� ��������ǰ�����ֵ
//	if (pos1 != v1.end())
//	{
//		v1.insert(pos1, 30);
//	}																	 
//	//��Χfor���б���
//	for (auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
////������ʧЧ����
//int main()
//{
//	////����һ�µ�����
//	//vector<int> v = { 1,2,3,4 };
//	//v.reserve(5);
//	//vector<int>::iterator it = v.begin();
//	////v.reserve(5);
//	////������ʧЧ����ΪreserveʹitʧЧ�� �����������reserve����it֮ǰ
//	////��Ӱ�������ʧЧ�Ĳ���
//	////reserve/resize
//	////insert/push_back/erase ������ ���ռ�Ķ�������
//	//while (it != v.end())
//	//{
//	//	cout << *it << " ";
//
//	//}
//	//cout << endl;
//	//ɾ�����������е�ż��
//	vector<int> v = { 1,2,3,4 };
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//		{
//			it = v.erase(it);//vsɾ��it�Ժ� itʧЧ�� ����PJ STL����������˼��
//		}
//		else
//		{
//			++it;
//		}
//	
//
//	}
//	cout << endl;
//	for (auto e : v)
//	{
//		cout << e << " ";
//
//	}
//	cout << endl;
//
//
//}
//
//
////int main()
////{
////
////	//test_vector1();
////	//test_vector2();
////	//test_vector3();
////	//test_vector4();
////	//test_vector5();
////	return 0;
////}
//
//
//
//
//
//
//




#include"vector.h"
int main()
{
	hdzc::test_vector1();
	hdzc::test_vector2();
	hdzc::test_vector3();
	hdzc::test_vector4();

	return 0;
}