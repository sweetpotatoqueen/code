#pragma warning (disable:4996)
#include <stdio.h>
int main()
{
	int n, count = 0, x, y, z;
	scanf("%d", &n);

	if (n < 100)
		printf("%d", n);

	else
	{
		for (int i = 101; i <= n; i++)
		{
			x = i / 100;
			y = (i / 10) % 10;
			z = i % 10;

			if ((x - y) == (y - z))
				count++;
		}
		printf("%d", count + 99);
	}
}