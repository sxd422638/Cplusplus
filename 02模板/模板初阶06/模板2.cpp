//#include <iostream>
//#include <assert.h>
//using namespace std;

//void swap_int(int* pa, int* pb);
//void swap_double(double* pa, double* pb);
//
//// ���ͱ�� -> ���Խ����Ҫд���swap���������⣬�Ŷ��swap�����߼�����ͬ�������д������Ͳ�һ��
//// ģ�����swapʵ��
//namespace bit
//{
//	// ����ģ��
//	template<class T> // template<typename T>
//	inline void swap(T& x1, T& x2)
//	{
//		T tmp = x1;
//		x1 = x2;
//		x2 = tmp;
//	}
//}
//
//int main()
//{
//	// C�����У����ǵ�д��������������������͵Ķ�����Ҫ��������ô���ﻹ��Ҫд����swap����
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.2;
//	// swap_int(&a, &b);
//	// swap_double(&c, &d);
//
//	// C++��ν����C++��׼���о���һ��swap��������ʹ��
//	char e = 'a', f = 'b';
//	bit::swap(a, b);
//	bit::swap(c, d);
//	bit::swap(e, f);
//
//	return 0;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//
//template<class T>
//void Func(size_t n)
//{
//	T* p = new T[n];
//	// ...
//	delete[] p;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	// �������Լ�ȥ���ݣ���ʽʾ����
//	Add(a1, a2);
//	Add(d1, d2);
//	Add(a1, (int)d2);
//
//	// ָ��T�����ͣ���ʽ��ʵ����
//	Add<int>(a1, d2);
//	Add<double>(a1, d2);
//
//	// �����Func������ֻ����ʾʵ����
//	Func<int>(10);
//
//	return 0;
//}

// ר�Ŵ���int�ļӷ�����
// �ֳɵ�  ��������
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// ͨ�üӷ�����
//// ģ�壬��Ҫʵ�������ܵ���
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2);      // ->�ֳɺ���
//	Add(1.1, 2.2);  // ->ģ��ʵ������
//	Add<int>(1, 2);
//
//	return 0;
//}

namespace bit_c //c����     ����һ���µ������ռ�
{
	// ˳��� --> ���Զ�̬����������
	// C���Զ����˳���-�� ���ݺͷ����Ƿֿ�����
	// ����1�������ǿ��Ա����ĵ�  CPP��ν��->��ķ�װ �Ȱ����ݺͷ����ŵ�һ��ͨ�������޶�����������
	// ����2���������࣬Ҫͬʱ����SeqList seq1,Ҫ��int; SeqList seq2,��double.
	//        �������2��C����ȥ���������ʵ�֣������߼�һ�������Ͳ�һ��  CPP��ν��-����ģ��
	typedef int SLDataType;
	typedef struct SeqList
	{
		SLDataType*   _a;
		size_t _size;
		size_t _capacity;
	}SeqList;

	void SeqListInit(SeqList* ps, size_t n)     // cpp->���캯��
	{}
	void SeqListDestory(SeqList* ps)            // cpp->��������
	{}
	void SeqListPrint(SeqList* ps);
	void SeqListCheckCapacity(SeqList* ps);
	void SeqListPushBack(SeqList* ps, SLDataType x)  // c����������cpp->������ֻ��һ��������ʵ��Ҳ����������һ����������this
	{}
	void SeqListPopBack(SeqList* ps);
}

namespace bit_cpp //c++
{
	// typedef int SLDataType;
	template<class T>
	class SeqList
	{
	public:
		SeqList(size_t n = 10)//c�����еĳ�ʼ����Ӧ--->���캯��
			:_a(new T[n])
			, _size(0)
			, _capcity(n)
		{}

		~SeqList()			//c�����е����ٶ�Ӧ--->��������
		{
			if (_a != nullptr)
			{
				delete[] _a;
				_size = 0 ; 
				_capcity = 0;
			}

		}

		void PushBack(T x)//c++ ���ö��帴�Ƶ������� ��Ϊ�������� ֱ�ӵ��ü���
		{
			// ...
		}

		// a[i]
		// a[i] = 0;
		T& operator[](size_t i)//����һ�������   []
		{
			// ����i���ʵ�λ���Ƿ�Ϸ�
			assert(i < _size);

			return _a[i];
		}

		// ...

	private:				//���ܱ��ĵķ���˽����
		T*           _a;
		size_t      _size;//�ռ��ڵ�������Ŀ
		size_t      _capcity;//�ռ�Ĵ�С
	};
	
}

int main()
{
	// C��ʹ��˳���
	bit_c::SeqList seqc;
	bit_c::SeqListInit(&seqc, 10);
	// ...bit_c::SeqListDestory(&seqc);
	bit_c::SeqListPushBack(&seqc, 1);
	bit_c::SeqListPushBack(&seqc, 2);
	bit_c::SeqListPushBack(&seqc, 3);
	bit_c::SeqListDestory(&seqc);


	// CPP��ʹ��˳���
	bit_cpp::SeqList<int> seqcpp1;//��ʾʵ����
	seqcpp1.PushBack(1);
	seqcpp1.PushBack(2);
	seqcpp1.PushBack(3);
	
	// ����i��λ�õ�����
	cout << seqcpp1[0] << endl;
	// д��i��λ������
	// seqcpp1.operator[](0) = 0;
	seqcpp1[0] = 0;
	seqcpp1[1] = 0;

	bit_cpp::SeqList<double> seqcpp2;//��ʾʵ����
	seqcpp2.PushBack(1.1);
	seqcpp2.PushBack(2.2);
	seqcpp2.PushBack(3.3);


	return 0;
}

//#include <iostream>
//#include <string>
//
//int main()
//{
//	std::string s1;
//	std::string s2("helloworld");
//	std::string s3(s2);  // std::string s3 = s2;
//	s1 = s3;
//
//	// �������ַ�ʽ��������
//	std::string s4(s3, 5, 5);
//	std::string s5(5, 'a');
//
//	std::cout << s1 << std::endl;
//	std::cout << s2 << std::endl;
//	std::cout << s3 << std::endl;
//	std::cout << s4 << std::endl;
//	std::cout << s5 << std::endl;
//
//	// ���������һ������ȡ�����е�ÿ���ַ�
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		std::cout << s1[i] << " ";
//	}
//	std::cout << std::endl;
//
//
//	return 0;
//}
