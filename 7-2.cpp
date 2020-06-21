/*입력으로 하나의 수열이 주어진다.이 중 오름차순으로 정렬되어 있는 가장 긴 구간을 찾아서 
그 구간의 길이를 출력하는 프로그램을 작성하라.
예를 들어 수열이 2, 3, -2, -2, -2, 7, 7, 9, 10, 10, 9, -3라면 밑줄 친 구간이 가장 긴 구간이고 
그 길이는 8이다.입력은 키보드로부터 받으며 먼저 수열의 길이 N이 주어지고 이어서 N개의 정수들이 주어진다.*/
#pragma warning (disable:4996)
#define MAX 20
#include <stdio.h>
int main()
{
	int n, data[MAX] = { 0 }, count = 0, max;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	max = count;
	for (int j = 0; j < n - 1; j++)
	{
		if (data[j + 1] >= data[j])
		{
			count++;
			if (max < count)
				max = count;

		}
		if (data[j + 1] < data[j])
		{
			count = 0;
			continue;
		}
	}
	printf("%d", max + 1);
}