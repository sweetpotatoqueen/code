#include <stdio.h>
#include <ctype.h>
int countword(char* s)
{
	int count = 0, waiting = 1;
	for(int i=0; s[i]!=NULL; ++i)
		if (isalpha(s[i]))
		{
			if (waiting)
			{
				count++;
				waiting = 0;
			}
		}
	else
		waiting = 1;

	return count;
}
int main()
{
	char buffer[100];
	gets_s(buffer, 100);
	int result = countword(buffer);
	printf("%d", result);
}

