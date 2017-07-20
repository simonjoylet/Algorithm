#include <iostream>
#include <stdio.h>
using namespace std;

int binary_search(int * a, int N, int v)
{
	if (v < a[0] || v > a[N - 1]) return -1;
	int left = 0;
	int right = N - 1;
	// 循环条件不能少了等号，数组可能只有一个元素
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == v) return mid;
		else if (v < a[mid]) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}


int main(int argc, char ** argv)
{
	int a[] = { 1, 2, 3, 4, 5, 7, 9, 11, 32, 55, 78 };
	cout << binary_search(a, sizeof(a) / sizeof(int), 55) << endl;
	getchar();
	return 0;
}