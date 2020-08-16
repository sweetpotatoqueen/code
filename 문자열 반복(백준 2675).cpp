#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#define MAX 20
void print(char a[], int b)
{
	for (int i = 0; i < strlen(a); i++)
		for (int j = 0; j < b; j++)
			printf("%c", a[i]);
	printf("\n");
}
int main()
{
	int n, j;
	char data[MAX];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &j);
		scanf("%s", data);
		print(data, j);
	}
}