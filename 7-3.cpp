/*입력으로 N개의 정수와 또 하나의 정수 K가 주어진다. 
N개의 정수들 중에서 합이 K를 초과하지 않으면서 가장 긴 구간을 찾아 
그 구간의 길이를 출력하는 프로그램을 작성하라. 
키보드로부터 먼저 정수의 개수 N을 입력받고, 이어서 N개의 정수를 입력 받은 후, 마지막으로 정수 K를 입력 받는다.*/
#pragma warning (disable:4996)
#define MAX 20
#include <stdio.h>
int main()
{
	int n, data[MAX] = { 0 }, max1, max2, k, count = 0, sum = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	scanf("%d", &k);

	max1 = count;
	max2 = sum;

	for (int j = 0; j < n; j++)
	{
		if (data[0] > k)
			break;
		sum += data[j];
		count++;
		if (max1 < count)
			max1 = count;
		if (max2 < sum)
			max2 = sum;
		if (sum > k)
		{
			count = 0;
			sum = 0;
			j--;
		}
	}
	printf("%d", max1);
}