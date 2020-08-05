#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#define MAX 80
int main()
{
	int n, sum, result=0;
	char data[MAX];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		sum = 0;
		result = 1;
		scanf("%s", data);
		for (int j = 0; j < strlen(data); j++)
		{
			if (data[j] == 'O')
			{
				sum += result;
				result++;
			}
			else if (data[j] == 'X')
				result = 1;
		}
		printf("%d\n", sum);
	}
}