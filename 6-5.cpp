/*입력으로 두 개의 양의 정수를 받는다. 그런 다음 두 정수를 사전식 순서(lexicographic order)로 출력하는 프로그램을 작성하라.
예를 들어 두 정수가 75와 111이라면 75는 7로 시작하므로 사전식 순서에서는 1로 시작하는 111보다 나중에 나와야 한다.
즉 111, 75의 순서로 출력해야 한다. 단, stdio.h 이외의 라이브러리나 strcmp 등의 문자열을 비교하는 라이브러리 함수를 사용해서는 안된다*/
#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 10
int main()
{
	int n, m, count1 = 0, count2 = 0, tmp, min;
	int a[MAX] = { 0 }, b[MAX] = { 0 };

	scanf("%d %d", &n, &m);
	int n1 = n, m1 = m;

	while (n != 0)
	{
		tmp = n % 10;
		count1++;
		n /= 10;
	}
	while (m != 0)
	{
		tmp = m % 10;
		count2++;
		m /= 10;
	}

	n = n1; m = m1;
	for (int i = count1 - 1; i >= 0; i--)
	{
		a[i] = n % 10;
		n /= 10;
	}
	for (int i = count2 - 1; i >= 0; i--)
	{
		b[i] = m % 10;
		m /= 10;
	}

	min = (count1 > count2) ? count2 : count1;

	for (int i = 0; i < min; i++)
	{
		if (a[i] > b[i])
		{
			tmp = n1;
			n1 = m1;
			m1 = tmp;
			break;
		}
		if (a[i] == b[i] && i == min - 1 && min == count2)
		{
			tmp = n1;
			n1 = m1;
			m1 = tmp;
		}
	}
	printf("%d %d", n1, m1);
}