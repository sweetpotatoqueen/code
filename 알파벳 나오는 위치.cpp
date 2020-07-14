#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
int main()
{
	char data[101] = { NULL }, count[101] = { NULL };
	scanf("%s", data);

	for (int i = 0; i < 26; i++)
		count[i] = -1;

	for(int i='a'; i<='z'; i++)
		for (int j = 0; j < strlen(data); j++)
		{
			if (data[j] == i)
			{
				count[i - 97] = j;
				break;
			}
		}

	for (int i = 0; i < 26; i++)
		printf("%d ", count[i]);
}