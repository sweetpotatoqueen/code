#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 1001
void bubble_sort(int n, int data[])
{
	for(int i=n-1; i>0; i--)
		for(int j=0; j<i; j++)
			if (data[j] > data[j + 1])
			{
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
}
int main()
{
	int n, time[MAX], sum = 0, min_sum=0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &time[i]);

	bubble_sort(n, time);

	for (int i = 0; i < n; i++)
	{
		sum += time[i];
		min_sum += sum;
	}
	printf("%d", min_sum);
}