#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
int main()
{
	char c[1000000];
	int count[26] = { 0, };
	scanf("%s", c);
	int index;
	int len = strlen(c);

	for (int i = 'a'; i <= 'z'; i++)
		for (int j = 0; j < len; j++)
			if (i == c[j])
				count[i - 'a']++;
	for (int i = 'A'; i <= 'Z'; i++)
		for (int j = 0; j < len; j++)
			if (i == c[j])
				count[i - 'A']++;

	int max = count[0];
	int result=0;

	for (int i = 1; i < 26; i++)
		if (max < count[i])
		{
			max = count[i];
			index = i;
		}

	for (int i = 0; i < 26; i++)
		if (max == count[i])
			result++;

	if (result > 1)
		printf("?");//두 개 이상이면 ? 출력
	else
		printf("%c", index + 'A');//가장 많이 나온 수 대문자로 출력

}