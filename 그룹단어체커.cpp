#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#define MAX 1000
int groupword(char a[], int len)
{
	int key;

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			if (a[i] == a[j])
			{
				key = j - i;
				if (key > 1)
					if (a[j - 1] != a[j])
						return 0;
			}
	return 1;
}
int main()
{
	int n, sum=0;
	char m[MAX];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", m);
		sum += groupword(m, strlen(m));
	}

	printf("%d", sum);
}
