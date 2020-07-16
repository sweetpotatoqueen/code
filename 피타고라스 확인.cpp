#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 10000
int main()
{
	int a, b, c, data[MAX] = { 0 }, i=0, count=0;
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0)
			break;
		if (a * a + b * b == c * c || b * b + c * c == a * a || a * a + c * c == b * b)
			data[i] = 1;
		else
			data[i] = -1;
		i++;
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		if (data[i] == 1)
			printf("right");
		else
			printf("wrong");
		printf("\n");
	}
}