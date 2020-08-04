#pragma warning (disable:4996)
#include <stdio.h>
#include <limits.h>
#include <malloc.h>
typedef struct customer {
	int age;
	char name[101];
}customer;
struct customer c[100001];
int main()
{
	int N, max = INT_MIN, min = INT_MAX;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %s", &c[i].age, c[i].name);
		if (min > c[i].age)
			min = c[i].age;
		if (max < c[i].age)
			max = c[i].age;
	}

	for (int i = min; i <=max; i++)
		for(int j=0; j<N; j++)
			if(c[j].age==i)
				printf("%d %s\n", c[j].age, c[j].name);
}