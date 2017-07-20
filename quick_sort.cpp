#include <iostream>
#include <stack>
using namespace std;

void swap(int * a, int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int partition(int * a, int low, int high)
{
	int v = a[low];
	int i = low;
	int j = high+1;
	while (i < j)
	{
		while (a[++i] < v && i < high);
		while (a[--j] > v && j > low);
		if (i < j) swap(a, i, j);
	}
	swap(a, low, j);
	return j;
}

// µÝ¹é
void qsort(int * a, int low, int high)
{
	if (high - low <= 0)return;
	int j = partition(a, low, high);
	qsort(a, low, j - 1);
	qsort(a, j + 1, high);
}

void quick_sort(int * a, int N)
{
	return qsort(a, 0, N - 1);
}

// ·ÇµÝ¹é
void quick_sort_2(int * a, int N)
{
	stack<pair<int, int> > st;
	st.push(make_pair(0, N - 1));
	while (st.size())
	{
		int low = st.top().first;
		int high = st.top().second;
		st.pop();
		if (high - low <= 0) continue;
		int j = partition(a, low, high);
		st.push(make_pair(low, j - 1));
		st.push(make_pair(j + 1, high));
	}
}

int main(int argc, char ** argv)
{
	int a[10] = { 1, 2, 2, -4, 5, 66, -5, 2, 8, 22 };
	quick_sort(a, 10);
	for (int i = 0; i < 10; ++i) cout << a[i] << " ";
	getchar();
	return 0;
}