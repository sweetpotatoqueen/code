#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 1000
int main()
{
	int n, data[MAX], count, countmax=0, temp[MAX];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j < i; j++)
			if (data[i] > data[j] && count < temp[j])
				count = temp[j];
				
		temp[i] = count + 1;

		if (countmax < temp[i])
			countmax = temp[i];
	}
	printf("%d", countmax);
}
