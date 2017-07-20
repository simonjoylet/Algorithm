#include <iostream>
using namespace std;

void swap(int * a, int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void sink(int * a, int k, int N)
{
	while (2 * k < N)
	{
		int j = 2 * k;
		if (j < N && a[j] < a[j + 1]) j++;
		if (a[k] >= a[j]) break;
		swap(a, k, j);
		k = j;
	}
}


void heap_sort(int * a, int N)
{
	for (size_t k = N / 2; k >= 1; k--)
	{
		sink(a, k, N);
	}
	while (N > 1)
	{
		swap(a, 1, N--);
		sink(a, 1, N);
	}
}

int main(int argc, char ** argv)
{
	int a[10] = { 1, 2, 4, -4, 5, 66, -5, 7, 8, 22 };
	heap_sort(a-1, 10);//a[0]”√≤ªµΩ
	for (int i = 0; i < 10; ++i) cout << a[i] << " ";
	getchar();
	return 0;
}