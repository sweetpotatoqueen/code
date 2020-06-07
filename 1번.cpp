#pragma warning (disable:4996)
#include <stdio.h>
int main()
{
	char x;
	printf("문자를 입력하시오:");
	scanf("%c", &x);

	printf("아스키 코드 값: %d", x);
}