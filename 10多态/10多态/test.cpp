//class Person
//{
//public:
//	string _name = "xxx"; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "peter";
//
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//
//	return 0;
//}

// 什么是菱形继承？菱形继承的问题？（数据冗余和二义性）如何解决？（虚继承）
// 虚继承是如何解决这个数据冗余和二义性的？
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
//// 菱形继承，内存模型(在内存中是如何存储的？)
//// 注意监视窗口看到的有时是被编译器处理过的，不一定是实际的，实际中我们要去看内存窗口
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
//// 菱形虚拟继承，内存模型(在内存中是如何存储的？)
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

// 继承 -> 白箱复用  （强关联关系）  is-a关系
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

// 组合 -> 黑箱复用 （弱关联关系）  has-a关系
class N
{
protected:
	M _mm;
	int _n;
};

// 两个类的关系更符合is-a就用继承
// 两个类的关系更符合has-a就用组合
// 都可以，优先使用组合 

////////////////////////////////////////////////////////////////////////////////////////////


// 虚函数是实现多态的条件之一
//class Person {
//public:
//	// 虚函数重写的协变：返回值可以不同，但是必须是父类关系的指针或者引用
//	virtual Person BuyTicket() { cout << "Person 买票-全价" << endl; return this; }
//};
//
//// Student的虚函数的函数名、参数、返回值跟Perosn中的虚函数都相同，Student的虚函数重写了Person中的虚函数
//class Student : public Person {
//public:
//	virtual Student* BuyTicket() { cout << "Student 买票-半价" << endl; return this; }
//};

//class A
//{};
//
//class B : public A
//{};
//
//class Person {
//public:
//	// 虚函数重写的协变
//	virtual A* BuyTicket() { cout << "Person 买票-全价" << endl; return nullptr; }
//};
//
//// Student的虚函数的函数名、参数、返回值跟Perosn中的虚函数都相同，Student的虚函数重写了Person中的虚函数
//class Student : public Person {
//public:
//	virtual B* BuyTicket() { cout << "Student 买票-半价" << endl; return nullptr; }
//};
//
//
//// 达到多态的条件：
//// 1.虚函数的重写。(子类的虚函数和父类的虚函数的函数名、参数、返回值都相同(协变)，才满足重写)
//// 2.父类的指针/引用去调用虚函数
//// 多态：去完成某一行为，不同的对象去完成，效果是不一样的。
//
//// 虚函数重写例外：
//// 1、协变（返回值是父子类关系的指针或引用）
//// 2、子类的虚函数可以不加virtual
//// 3、析构函数名看起来不相同，但是构成重写（实际是被处理成了destrucator）
//
////void Func(Person* ptr)
////{
////	ptr->BuyTicket();
////}
//
//// 
//// 不满足多态，调用谁的函数->看类型
//// 满足多态，调用谁的函数->看指向的对象
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
	virtual ~Person() // 析构函数的名称destructor
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	virtual ~Student()  // 析构函数的名称destructor
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
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//// 1.构成多态，指针或者引用，指向谁调用谁的虚函数。 看指针或者引用指向的对象
//// 2.不构成多态，指针或者引用，类型是谁的调用就是谁。看指针或者引用的类型
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
//	virtual void Drive()  override { cout << "Benz-舒适" << endl; }
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
//	virtual void Drive() = 0; // 纯虚函数
//};
//
//// 包含纯虚函数的类叫做抽象类（也叫接口类），抽象类不能实例化出对象
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
//	BYD byd1;//这里继承了父类的纯虚函数     重写一下就好了 
//	BYD byd2;
//
//	BMW bmw1;
//	BMW bmw2;
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////
// 原理
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
//	virtual void BuyTicket() { cout << "Person::BuyTicket()->买票-全价" << endl; }
//	int _a = 1;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "Person::Student()->买票-半价" << endl; }
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
//	//void(*p)();  // 函数指针定义很怪，不好理解
//	V_FUNC p;      // 所以我们喜欢这样去定义
//	p = func; // 定义个函数指针 指向func
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