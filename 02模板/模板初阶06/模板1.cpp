#include<iostream>
using namespace std;

namespace bit
{

	//º¯ÊýÄ£°å
	template<calss T>
	void swap(T& x1 ,T& x2)
	{
		T tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
}


int main()
{
	int a = 0, b = 1;
	swap(a, b);


}