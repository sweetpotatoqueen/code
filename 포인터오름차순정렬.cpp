#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
void sort(int * p)
{
	for (int i = 0; i <= sizeof(p)-1; i++) {
		for (int j = i+1; j <= sizeof(p); j++)
			if ( *(p + i) > *(p + j))
			{
				int temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
	}
	return;
}
int main()
{
	int N, count = 0;
	scanf("%d", &N);

	int * n = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
		scanf("%d", (n + i));

	sort(n);

	for (int i = 0; i < N; i++) 
		printf("%d\n", *(n + i));
}