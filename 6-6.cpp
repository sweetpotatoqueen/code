/*입력으로 양의 정수들이 주어진다. 각 정수들은 8자리 이내의 정수들이다. 
이 정수들을 사전식 순서(lexicographic order)로 정렬하여 출력하는 프로그램을 작성하라. 
예를 들어 입력 정수들이 75, 111, 120, 3456, 9, 12, 67, 91이라면 111, 12, 120, 3456, 67, 75, 9, 91의 순서로 출력한다.
입력은 먼저 정수의 개수 n이 주어지고 이어서 n개의 양의 정수들이 주어진다*/
#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 10
int main()
{
	int n, tmp, max;
	int p[MAX] = { 0 };

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		p[i] = k;
	}

	for (int j = n - 1; j >= 0; j--) {
		for (int i = 0; i < j; i++) {
			int p1 = p[i], p2 = p[i + 1];
			int count1 = 0, count2 = 0;

			while (p[i] != 0)
			{
				tmp = p[i] % 10;
				count1++;
				p[i] /= 10;
			}
			while (p[i + 1] != 0)
			{
				tmp = p[i + 1] % 10;
				count2++;
				p[i + 1] /= 10;
			}

			p[i] = p1; p[i + 1] = p2;
			int a[MAX] = { 0 }, b[MAX] = { 0 };
			for (int k = count1 - 1; k >= 0; k--)
			{
				a[k] = p[i] % 10;
				p[i] /= 10;
			}
			for (int k = count2 - 1; k >= 0; k--)
			{
				b[k] = p[i + 1] % 10;
				p[i + 1] /= 10;
			}

			max = (count1 < count2) ? count2 : count1;
			p[i] = p1, p[i + 1] = p2;

			for (int k = 0; k < max; k++)
			{
				if (a[k] > b[k])
				{
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
					break;
				}
				else if (a[k] < b[k])
					break;

				if (k == max - 1 && max == count1) {
					tmp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = tmp;
				}

			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
}