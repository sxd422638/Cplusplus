//class Person
//{
//public:
//	string _name = "xxx"; // ����
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//int main()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	a._name = "peter";
//
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//
//	return 0;
//}

// ʲô�����μ̳У����μ̳е����⣿����������Ͷ����ԣ���ν��������̳У�
// ��̳�����ν�������������Ͷ����Եģ�
//class A
//{
//public:
//	int _a;
//};
//
//class B : public A
//{
//public:
//	int _b;
//};
//
//class C : public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//#include<list>
//// ���μ̳У��ڴ�ģ��(���ڴ�������δ洢�ģ�)
//// ע����Ӵ��ڿ�������ʱ�Ǳ�������������ģ���һ����ʵ�ʵģ�ʵ��������Ҫȥ���ڴ洰��
////list<int> l;
////l.push_back(1);
////l.push_back(2);
////l.push_back(3);
////l.push_back(4);
//int main()
//{
//	D d;
//	cout << sizeof(d) << endl;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	return 0;
//}


//class A
//{
//public:
//	//int _a[1000];
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//#include<list>
//// ��������̳У��ڴ�ģ��(���ڴ�������δ洢�ģ�)
//int main()
//{
//	D d;
//	cout << sizeof(d) << endl;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	return 0;
//}


class X
{
protected:
	int _x;
};

// �̳� -> ���临��  ��ǿ������ϵ��  is-a��ϵ
class Y : public X
{
protected:
	int _y;
};

class M
{
protected:
	int _m;
};

// ��� -> ���临�� ����������ϵ��  has-a��ϵ
class N
{
protected:
	M _mm;
	int _n;
};

// ������Ĺ�ϵ������is-a���ü̳�
// ������Ĺ�ϵ������has-a�������
// �����ԣ�����ʹ����� 

////////////////////////////////////////////////////////////////////////////////////////////


// �麯����ʵ�ֶ�̬������֮һ
//class Person {
//public:
//	// �麯����д��Э�䣺����ֵ���Բ�ͬ�����Ǳ����Ǹ����ϵ��ָ���������
//	virtual Person BuyTicket() { cout << "Person ��Ʊ-ȫ��" << endl; return this; }
//};
//
//// Student���麯���ĺ�����������������ֵ��Perosn�е��麯������ͬ��Student���麯����д��Person�е��麯��
//class Student : public Person {
//public:
//	virtual Student* BuyTicket() { cout << "Student ��Ʊ-���" << endl; return this; }
//};

//class A
//{};
//
//class B : public A
//{};
//
//class Person {
//public:
//	// �麯����д��Э��
//	virtual A* BuyTicket() { cout << "Person ��Ʊ-ȫ��" << endl; return nullptr; }
//};
//
//// Student���麯���ĺ�����������������ֵ��Perosn�е��麯������ͬ��Student���麯����д��Person�е��麯��
//class Student : public Person {
//public:
//	virtual B* BuyTicket() { cout << "Student ��Ʊ-���" << endl; return nullptr; }
//};
//
//
//// �ﵽ��̬��������
//// 1.�麯������д��(������麯���͸�����麯���ĺ�����������������ֵ����ͬ(Э��)����������д)
//// 2.�����ָ��/����ȥ�����麯��
//// ��̬��ȥ���ĳһ��Ϊ����ͬ�Ķ���ȥ��ɣ�Ч���ǲ�һ���ġ�
//
//// �麯����д���⣺
//// 1��Э�䣨����ֵ�Ǹ������ϵ��ָ������ã�
//// 2��������麯�����Բ���virtual
//// 3����������������������ͬ�����ǹ�����д��ʵ���Ǳ��������destrucator��
//
////void Func(Person* ptr)
////{
////	ptr->BuyTicket();
////}
//
//// 
//// �������̬������˭�ĺ���->������
//// �����̬������˭�ĺ���->��ָ��Ķ���
//void Func(Person& rp)
//{
//	rp.BuyTicket();
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Func(p);
//	Func(s);
//
//	return 0;
//}

class Person
{
public:
	virtual ~Person() // ��������������destructor
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	virtual ~Student()  // ��������������destructor
	{
		cout << "~Student()" << endl;
	}
};

int main()
{
	//Person p;
	//Student s;
	Person* p1 = new Student;
	delete p1;

	Person* p2 = new Person;
	delete p2;

	// p->destructor()
	// free(p)

	return 0;
}


//
//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//// 1.���ɶ�̬��ָ��������ã�ָ��˭����˭���麯���� ��ָ���������ָ��Ķ���
//// 2.�����ɶ�̬��ָ��������ã�������˭�ĵ��þ���˭����ָ��������õ�����
//
//class A
//{
//public:
//	~A(){cout << "~A()" << endl;}
//};
//
//class B : public A
//{
//public:
//	~B(){cout << "~B()" << endl;}
//};
//
//class Car
//{
//public:
//	void Drive() {}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()  override { cout << "Benz-����" << endl; }
//};
//
//int main()
//{
//	A* p1 = new A;
//	delete p1;
//
//	A* p2 = new B;
//	delete p2;
//
//	/*Student s;
//	Person  p;
//	Person* ptr = &s;
//	ptr->BuyTicket();
//	ptr = &p;
//	ptr->BuyTicket();*/
//
//
//
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() = 0; // ���麯��
//};
//
//// �������麯��������������ࣨҲ�нӿ��ࣩ�������಻��ʵ����������
//class BYD : public Car
//{
//	virtual void Drive()
//	{}
//};
//
//class BMW : public Car
//{
//	virtual void Drive()
//	{}
//};
//
//int main()
//{
//	//Car c;
//	BYD byd1;//����̳��˸���Ĵ��麯��     ��дһ�¾ͺ��� 
//	BYD byd2;
//
//	BMW bmw1;
//	BMW bmw2;
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////
// ԭ��
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//private:
//	int _b = 1;
//	char _c = 'a';
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base b1;
//	Base b2;
//
//	return 0;
//}


//class Person {
//public:
//	virtual void BuyTicket() { cout << "Person::BuyTicket()->��Ʊ-ȫ��" << endl; }
//	int _a = 1;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "Person::Student()->��Ʊ-���" << endl; }
//	int _b = 2;
//};
//
//int main()
//{
//	Person p;
//	Student s;
//
//	Person* ptr = &p;
//	ptr->BuyTicket();
//
//	ptr = &s;
//	ptr->BuyTicket();
//
//	return 0;
//}


class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}

	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}

private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}

	virtual void Func4()
	{
		cout << "Derive::Func4()" << endl;
	}
private:
	int _d = 2;
};

typedef void(*V_FUNC)();


//int main()
//{
//	Base b;
//	Derive d;
//
//	V_FUNC* vftptr_d = (V_FUNC*)(*((int*)&d));
//	cout << vftptr_d << endl;
//
//	V_FUNC* vftptr_b = (V_FUNC*)(*((int*)&b));
//	cout << vftptr_b << endl;
//
//	return 0;
//}

//typedef void(*V_FUNC)();
//typedef int INT;
//
//void func()
//{
//	cout << "func()" << endl;
//}
//
//int main()
//{
//	INT i;
//	//void(*p)();  // ����ָ�붨��ܹ֣��������
//	V_FUNC p;      // ��һ�����ᱻ�������������Ĵ���
//	p = func; // ���������ָ�� ָ��func
//	p();
//	(*p)();
//
//	return 0;
//}



typedef void(*V_FUNC)();

//int a[10];
//int* p = a;

// V_FUNC table[10];
// V_FUNC* p = table;
void PrintVFTable(V_FUNC* p)
{
	for (int i = 0; p[i] != 0; ++i)
	{
		printf("vtable[%d]:%p->", i, p[i]);
		V_FUNC f = p[i];
		f() ;
	}
}

int main()
{
	Derive d;
	Derive* ptr = &d;
	PrintVFTable((V_FUNC*)ptr);
}
#include <iostream>
using namespace std;

//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a = 1;
//};
//
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b = 2;
//};

//// ����ָ��д�����ܱ�Ť���������Ǻ���ָ�������ͨ����typedef
//typedef void(*VF_PTR)();
////int* a[10]
////VF_PTR table[10]
//void PrintVFTable(VF_PTR* table)
//{
//	// ��ӡ���
//	for (size_t i = 0; table[i] != 0; ++i)
//	{
//		printf("vf_table[%d]:%p->", i, table[i]);
//		VF_PTR ptr = table[i];
//		ptr();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Base b;
//	Derive d;
//	//cout << *((int*)&b) << endl;
//	//cout << (void*)(int)b << endl;
//	// ȡ�����ָ�봫��ȥ
//	PrintVFTable((VF_PTR*)(*((int*)&b)));
//	PrintVFTable((VF_PTR*)(*((int*)&d)));
//
//
//	return 0;
//}

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

// ����ָ��д�����ܱ�Ť���������Ǻ���ָ�������ͨ����typedef
typedef void(*VF_PTR)();
//int* a[10]
//VF_PTR table[10]
void PrintVFTable(VF_PTR* table)
{
	// ��ӡ���
	for (size_t i = 0; table[i] != 0; ++i)
	{
		printf("vf_table[%d]:%p->", i, table[i]);
		VF_PTR ptr = table[i];
		ptr();
	}
	cout << endl;
}

//int main()
//{
//	Base1 b1;
//	Base2 b2;
//	Derive d;
//
//	PrintVFTable((VF_PTR*)(*(int*)&b1));
//	PrintVFTable((VF_PTR*)(*(int*)&b2));
//
//	cout << sizeof(d) << endl;
//	PrintVFTable((VF_PTR*)(*(int*)&d));
//	PrintVFTable((VF_PTR*)(*(int*)((char*)&d + sizeof(Base1))));
//
//	return 0;
//}

// дһ�δ�����֤����Ǵ����ĵģ�
//int main()
//{
//	int i = 0;
//	printf("ջ������ַ��%p\n", &i);
//
//	int* p1 = new int;
//	printf("�ѱ�����ַ��%p\n", p1);
//
//	static int j = 0;
//	printf("���ݶα�����ַ��%p\n", &j);
//
//	char* p2 = "hello world";
//	printf("�����(������)������ַ��%p\n", p2);
//
//	Base1 b1;
//	Base2 b2;
//	printf("Base1����ַ��%p\n", *((int*)&b1));
//	printf("Base2����ַ��%p\n", *((int*)&b2));
//
//	return 0;
//}

//class A{
//public:
//	A(char *s) { cout << s << endl; }
//	~A(){}
//};
//
//class B :virtual public A
//{
//public:
//	B(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//
//class C :virtual public A
//{
//public:
//	C(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//
//class D :public B, public C
//{
//public:
//	D(char *s1, char *s2, char *s3, char *s4)
//		:B(s1, s2)
//		,C(s1, s3)
//		,A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//
//
//
//int main() {
//	D *p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
//	virtual void test(){ func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0){ std::cout << "B->" << val << std::endl; }
//};
//
//int main(int argc, char* argv[])
//{
//	B*p = new B;
//	p->test();
//	return 0;
//}

class A
{
public:
	virtual void func1(int val = 1) { std::cout << "A->" << val << std::endl; }
	void func2(int val = 2) { std::cout << "A->" << val << std::endl; }
};

class B : public A
{
public:
	virtual void func1(int val) { std::cout << "B->" << val << std::endl; }
};

// ����̽�����ַ�ʽ
// 1��������  �����������⣬��ٷ��ĵ�����Ȩ�����鼮
// 2��������  �����������⣬������Դ����ȵײ�ʵ��


//
//int main(int argc, char* argv[])
//{
//	//A a;
//	//a.func1();
//	//a.func2();
//
//	//A* p = &a;
//	//p->func1();
//	//p->func2();
//
//	//printf("%p\n", &A::func1);
//	//printf("%p\n", &A::func2);
//
//	//A a;
//	//a.func1();
//	//a.func2();
//
//	return 0;
//}

// ʵ�ֶ�̬Ϊʲôֻ����ָ��������õ����أ�
void f1(A* ptr)
{
	ptr->func1();
}

void f2(A& ref)
{
	ref.func1();
}

void f3(A obj)
{
	obj.func1();
}

int main()
{
	A aa;
	B bb;

	f1(&aa);
	f1(&bb);

	f2(aa);
	f2(bb);

	f3(aa);
	f3(bb);


	return 0;
}