#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
void sort(int* p , int N)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-i-1 ; j++)
			if (*(p + j) > * (p + j + 1))
			{
				int temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = temp;
			}
	}
}
int main()
{
	int N;
	scanf("%d", &N);

	int *n = (int *)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
		scanf("%d", (n + i));

	sort(n, N);

	for (int i = 0; i < N; i++)
		printf("%d\n", *(n + i));
}