#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#define MAX 20
void change(int len, char ch[])
{
	for (int i = 0; i < len; i++)
	{
		if (ch[i] >= 'A' && ch[i] <= 'Z')
			ch[i] = ch[i] + 32;
	}
}
void array(int len, char ch[])
{
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
		{
			if (ch[i] > ch[j])
			{
				char temp = ch[i];
				ch[i] = ch[j];
				ch[j] = temp;
			}
		}
}
int main()
{
	char ch[MAX], c[MAX];
	scanf("%s %s", ch, c);

	int len_ch = strlen(ch);
	int len_c = strlen(c);

	change(len_ch, ch);
	change(len_c, c);

	if (strlen(ch) != strlen(c))
	{
		printf("no");
	}
	else
	{
		array(len_ch, ch);
		array(len_c, c);
		int flag = -1;
		if (stricmp(ch, c) == 0)
			flag = 0;
		else flag = 1;
		if (flag == 0)
			printf("yes");
		else if (flag == 1)
			printf("no");
	}
}