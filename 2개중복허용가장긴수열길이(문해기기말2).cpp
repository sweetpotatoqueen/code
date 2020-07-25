#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 100
int main()
{
	int N, data[MAX], array[MAX] = { 0 }, count = 0, max = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &data[i]);

	for (int i = 0; i < N; i++)
	{
		count = 0; 
        for (int i = 0; i < N; i++)
			array[i] = { 0 }; //초기화

		for (int j = i; j < N; j++)
		{
			array[data[j]]++;
			if (array[data[j]] >= 3) //3개 이상 나오면 count세기 전에 break
			{
				if (count > max)
					max = count;
				break;
			}
			count++;
			if (count > max)
				max = count;
		}
	}
	printf("%d", max);
}
