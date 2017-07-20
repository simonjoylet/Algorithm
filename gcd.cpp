#include <iostream>
#include <stdio.h>
using namespace std;

int gcd(int a, int b)
{
	// 保证a和b都为正数
	a = a > 0 ? a : -a;
	b = b > 0 ? b : -b;

	// 无需判断ab大小关系，
	// 如果a < b，第一次迭代之后ab会互换
	while (b > 0)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(int argc, char ** argv)
{
	cout << gcd(2400, -3060) << endl;
	getchar();
	return 0;
}