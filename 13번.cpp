#include <stdio.h>
void digit(int n)
{
	int i;
	int binary[32] = { 0 };
	for (i = 0; i < 32 && n>0; i++)
	{
		binary[i] = n % 2;
		n = n / 2;
	}
	for (i--; i >= 0; i--)
		printf("%d", binary[i]);
}
int main()
{
	digit(32);
}