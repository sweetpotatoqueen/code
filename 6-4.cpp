/*입력으로 n개의 구간(interval)이 주어진다. 각 구간은 구간의 시작점과 끝점으로 표현된다.
이 구간들을 시작점이 빠른 순서대로 정렬하여 출력하는 프로그램을 작성하라. 시작점이 같은 경우 끝점이 빠른 것을 먼저 출력한다.
입력 형식은 먼저 n의 값이 주어지고, 이어서 각 구간의 시작점과 끝점이 차례대로 주어진다. 
각 구간의 시작점과 끝점은 정수이고, 끝점은 항상 시작점보다 크거나 같다.*/
#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 10
int main()
{
	int n, data0[MAX] = { 0 }, data1[MAX] = { 0 }, temp, tempe;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &data0[i], &data1[i]);

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (data0[j] > data0[j + 1])
			{
				temp = data0[j];
				data0[j] = data0[j + 1];
				data0[j + 1] = temp;
				tempe = data1[j];
				data1[j] = data1[j + 1];
				data1[j + 1] = tempe;
			}
			if (data0[j] == data0[j + 1])
			{
				if (data1[j] > data1[j + 1])
				{
					temp = data1[j];
					data1[j] = data1[j + 1];
					data1[j + 1] = temp;
					tempe = data0[j];
					data0[j] = data0[j + 1];
					data0[j + 1] = tempe;

				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d %d\n", data0[i], data1[i]);
}