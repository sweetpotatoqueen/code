#pragma warning (disable:4996)
#include <stdio.h>
int main()
{
	int data1, data2;

	while (1)
	{
		scanf("%d %d", &data1, &data2);
	
		if (data1 == 0 && data2 == 0)
			break;
		if (data1 < data2)
		{
			if (data2 % data1 == 0)
				printf("factor\n");
			else
				printf("neither\n");
		}
		else if (data1 > data2)
		{
			if (data1 % data2 == 0)
				printf("multiple\n");
			else
				printf("neither\n");
		}
	}
}