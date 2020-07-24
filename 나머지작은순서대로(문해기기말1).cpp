#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 100
int main()
{
	int N, data[MAX], k, rest[MAX];
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &data[i]);

	scanf("%d", &k);

	for (int i = 0; i < N; i++)
		rest[i] = data[i] % k;

	for(int i=N-1; i>0; i--)
		for (int j = 0; j < i; j++)
		{
			if (rest[j] > rest[j + 1])
			{
				int temp = rest[j];
				rest[j] = rest[j + 1];
				rest[j + 1] = temp;
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
			else if (rest[j] == rest[j + 1])
			{
				if (data[j] > data[j + 1])
				{
					int temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
					int tmp = rest[j];
					rest[j] = rest[j + 1];
					rest[j + 1] = tmp;
				}
			}
		}

	for (int i = 0; i < N; i++)
		printf("%d ", data[i]);
}