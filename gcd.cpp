#include <iostream>
#include <stdio.h>
using namespace std;

int gcd(int a, int b)
{
	// ��֤a��b��Ϊ����
	a = a > 0 ? a : -a;
	b = b > 0 ? b : -b;

	// �����ж�ab��С��ϵ��
	// ���a < b����һ�ε���֮��ab�ụ��
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