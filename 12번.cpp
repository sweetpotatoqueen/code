#pragma warning (disable:4996)
#include <stdio.h>
void get_int(int *px, int *py, int sum)
{
	sum= *px + *py;
	printf("%d", sum);
}
int main()
{
	int x,y,sum=0;
	printf("두 개의 정수를 입력하시오:");
	scanf("%d,%d", &x, &y);
	get_int(&x, &y,sum);
}