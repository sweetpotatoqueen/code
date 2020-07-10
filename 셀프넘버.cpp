#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 10001
void checkselfnum()
{
	int result = 0, data[MAX] = { 0 };
	for (int n = 1; n <= 10000; n++)
	{
		if (n < 10)
		{
			result = n + n;
			data[result] = 1;
		}
		else if (n < 100)
		{
			result = n + (n / 10) + (n % 10);
			data[result] = 1;
		}
		else if (n < 1000)
		{
			result = n + (n / 100) + ((n % 100) / 10) + ((n % 100) % 10);
			data[result] = 1;
		}
		else if (n < 10000)
		{
			result = n + (n / 1000) + ((n % 1000) / 100) + (((n % 1000) % 100) / 10) + (((n % 1000) % 100) % 10);
			if(result<=10000)
				data[result] = 1;
		}
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (data[i] != 1)
			printf("%d\n", i);
	}
}
int main()
{
	checkselfnum();
}