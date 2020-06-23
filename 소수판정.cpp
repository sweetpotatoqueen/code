#pragma warning (disable:4996)
#include <stdio.h>
int checkprime(int n)
{
	for (int i = 2; i*i < n; i++)	
		if (n % i == 0)
			return 0;
		return 1;
}
int main()
{
	int a;
	scanf("%d", &a);

	int result = checkprime(a);

	if (result == 1)
		printf("prime");
	else 
		printf("not prime");
}
