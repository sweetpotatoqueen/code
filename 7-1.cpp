/*수열에서 큰 값이 작은 값보다 앞서 나오는 경우 두 값을 역전된(inverted) 쌍이라고 부른다.
예를 들어 수열 4, 2, 1, 1, 3에는(4, 2), (4, 1), (4, 1), (4, 3), (2, 1), (2, 1)의 총 6개의 역전된 쌍이 있다.
수열을 입력으로 받아서 역전된 쌍의 개수를 카운트하여 출력하는 프로그램을 작성하라.
키보드로부터 먼저 정수의 개수 N을 입력받고, 이어서 N개의 정수를 입력 받는다.*/
#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 10
int main()
{
	int n, data[MAX] = { 0 }, count = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	for (int i = 0; i < n; i++)
		for (int j = i; j < n - 1; j++)
			if (data[j + 1] < data[i])
				count++;
	printf("%d", count);
}