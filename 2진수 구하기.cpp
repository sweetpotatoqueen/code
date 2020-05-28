#pragma warning (disable:4996)
#include <stdio.h>
int main()
{
	int N,v=1;
	scanf("%d", &N);

	while (2 * v <= N)
		v *= 2;

	
	while (v > 0)
	{
		if (N >= v)
		{
			N = N - v;
			printf("1");
			v /= 2;
		}
		else
		{
			printf("0");
			v /= 2;
		}
	}
}