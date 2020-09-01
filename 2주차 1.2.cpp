/*1번
#pragma warning (disable:4996)
#include <stdio.h>
void sort_abc(int* a, int* b, int* c)
{
	if (*a > *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*b > *c)
	{
		int temp = *b;
		*b = *c;
		*c = temp;
	}
	if (*a > *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	sort_abc(&a, &b, &c);
	printf("%d %d %d\n", a, b, c);
}
*/
/*2번
#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 100
int find_max(int, int*);
int main()
{
	int N;
	int data[MAX];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &data[i]);
	int mx = find_max(N, data);
	printf("%d\n", mx);
}
int find_max(int n, int* data)
{
	int max = *data;

	for (int i = 1; i < n; i++)
		if (max < *(data + i))
			max = *(data + i);

	return max;
}*/
