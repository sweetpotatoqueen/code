/*사용자로부터 n개의 정수를 입력받아 크기순으로 정렬한 후 중복된 수를 제거하는 프로그램을 작성하라. 입력 형식은 먼저 n의 값이 주어지고 
이어서 n개의 정수들이 주어진다.  예를 들어 n=8이고 입력된 정수들이 4, 7, 4, 12, 4, 10, 9, 7 이라면 중복을 제거하고 
남은 정수들은 4, 7, 9, 10, 12 이다. 그러면 먼저 남은 정수의 개수 5를 출력하고 콜론(:)을 출력한 후 남은 정수들을
오름차순으로 출력한다.*/
#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 100
int main()
{
	int n, data[MAX] = { 0 }, count[MAX] = { 0 }, N, count1 = 0, temp, k = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &N);
		if (count[N] == 1)
			continue;
		data[k] = N;
		k++;
		count[N]++;
		count1++;
	}
	for (int i = 0; i < count1; i++)
		for (int j = 0; j < count1 - 1; j++)
			if (data[j] > data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}

	printf("%d:", count1);
	for (int i = 0; i < count1; i++)
		printf("%d ", data[i]);
}