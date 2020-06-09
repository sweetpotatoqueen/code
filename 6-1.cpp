/*키보드로 부터 연속해서 정수들을 입력받는다.
정수가 하나 씩 입력될 때 마다 현재까지 입력된 정수들을 오름차순으로 정렬하여 화면에 출력한다.
단, 새로 입력된 정수가 이미 배열에 저장되어 있다면 추가하는 대신 “duplicate”라고 출력한다.
사용자가 - 1을 입력하면 프로그램을 종료한다.*/
#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 100
int main()
{
	int data[MAX] = { 0 }, n = 0, N, count[MAX] = { 0 };

	while (1)
	{
		scanf("%d", &N);
		if (N == -1)
			break;

		int i = n - 1;

		if (count[N] == 1)
		{
			printf("duplicate\n");
			continue;
		}

		while (i >= 0 && data[i] > N)
		{
			data[i + 1] = data[i];
			i--;
		}
		data[i + 1] = N;
		n++;

		for (int i = 0; i < n; i++)
			printf("%d ", data[i]);

		printf("\n");

		count[N]++;
	}
}
