#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
void change(int len, char ch[])
{
    for (int i = 0; i < len; i++)
        if (ch[i] >= 'A' && ch[i] <= 'Z')
            ch[i] = ch[i] + 32;
}
int main() {

    int count = 0;
    char* words[MAX] = { 0 };
    char input[MAX];
    int LEN = strlen(input);

    scanf("%s", input);

    for (int i = 0; strcmp(input, "EOF") != 0;) {
        int boolean = 0;
        change(LEN, input);
        for (int j = 0; j < i && !boolean; j++) {
            if (strcmp(input, words[j]) == 0)
                boolean = 1;
        }

        if (!boolean) {
            words[i] = (char*)malloc(sizeof(char*) * LEN);
            strcpy(words[i], input);
            count++;
            i++;
        }
        scanf("%s", input);
        boolean = 0;
    }
    printf("%d", count);
}
