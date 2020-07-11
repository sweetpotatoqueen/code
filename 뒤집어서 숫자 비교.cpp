#pragma warning (disable:4996)
#include <stdio.h>
int main()
{
	int n, m, data1[3] = { 0 }, data2[3] = { 0 }, i = 0, j=0;
	scanf("%d %d", &n, &m);

	while (n != 0)
	{
		data1[i] = n % 10;
		n /= 10;
		i++;
	}
	while (m != 0)
	{
		data2[j] = m % 10;
		m /= 10;
		j++;
	}

	n = (data1[0] * 10 + data1[1]) * 10 + data1[2];
	m = (data2[0] * 10 + data2[1]) * 10 + data2[2];

	if (m > n)
		printf("%d", m);
	else
		printf("%d", n);
}