#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 100
int factorial(int n)
{
	if(n>1)
		return factorial(n - 1) * n;
	else
		return 1;
}
int main()
{
	int n, data[MAX] = { 0 }, i = 0, count = 0, j=0;
	scanf("%d", &n);

	int result = factorial(n);

	while (result != 0)
	{
		data[i] = result % 10;
		result /= 10;
		i++;
	}
	while(1)
	{
		if (data[j] == 0)
		{
			count++;
			j++;
		}
		else
		{
			printf("%d", count);
			break;
		}
	}
}
//
#include <stdio.h>
int main()
{
	int n;
	int cnt = 0;
	scanf("%d", &n);

	for (int i = 5; i <= n; i*=5) //팩토리얼 0개수는 2랑 5의 거듭제곱 중 작은 수 개수(대부분 5가 작음)
		cnt += (n / i);

	if (n == 0)
	{
		printf("1\n");
	}
	else
	{
		printf("%d\n", cnt);
	}

}