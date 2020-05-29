#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 100
int count[MAX][MAX] = { 0 };
void cross_count(int a1, int b1, int a2, int b2)
{
	int data[MAX][MAX] = { 0 };

	if (a1 == a2)
		for (int i = b1; i <= b2; i++)
			count[a1][i]++;

	else if (b1 == b2)
		for (int i = a1; i <= a2; i++)
			count[i][b1]++;
}
int main()
{
	int n, a1, a2, b1, b2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
		cross_count(a1, b1, a2, b2);
	}
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (count[i][j] >= 2)
				printf("[%d %d]\n", i, j);
}