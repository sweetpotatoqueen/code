#pragma warning (disable:4996)
#include <stdio.h>
int main()
{
	int a, b, c, result, data[1000] = { 0 }, k = 0, number[10] = { 0 };
	scanf("%d %d %d", &a, &b, &c);

	result = a * b * c;

	while (result > 0)
	{
		data[k]=result % 10;
		result /= 10;
		k++;
	}

	for(int j=0; j<k; j++)
		for (int i = 0; i <= 9; i++)
			if (data[j] == i)
				number[i]++;

	for (int i = 0; i <= 9; i++)
		printf("%d\n", number[i]);
}