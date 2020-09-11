#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000
int n;
char* word[MAX];
int count[MAX] = { 0 };
void sort()
{
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (strcmp(word[j], word[j + 1]) > 0) //j+1항이 j항보다 앞에 있으면 
            {
                char* tmp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = tmp;

                int temp = count[j];
                count[j] = count[j + 1];
                count[j + 1] = temp;
            }
        }
    }
}
int remove_head(char data[]) //조건 3
{
    int i = 0;
    while (!isalpha(data[i]))
        i++;
    return i;
}
int remove_tail(char data[])
{
    int j = strlen(data) - 1;
    while (!isalpha(data[j]))
        j--;
    return j;
}
void remove(char data[]) {
    int i = remove_head(data);
    int j = remove_tail(data);
    char data1[100];
    int index = 0;
    for (int k = i; k <= j; k++) {
        data1[index] = data[k];
        index++;
    }
    data1[index] = '\0';
    strcpy(data, data1);
}
int frequency(char data_[]) //빈도검사
{
    for (int i = 0; i < n; i++) {
        if (strcmp(word[i], data_) == 0) {
            count[i]++;
            return 1;
        }
    }
    return 0;
}
int alphabet(char data[]) // 조건 1
{
    for (int i = 0; i < strlen(data); i++) {
        if ((data[i] >= 'a' && data[i] <= 'z'))
            return 1;
    }
    return 0;
}
void check(char data[]) //조건 2
{
    if (alphabet(data) == 1)
    {
        remove(data);

        if (strlen(data) < 7)
            return;

        if (frequency(data) == 1)
            return;

        count[n]++;
        word[n++] = strdup(data);
    }
}
void change(int len, char ch[])
{
    for (int i = 0; i < len; i++)
        if (ch[i] >= 'A' && ch[i] <= 'Z')
            ch[i] = ch[i] + 32;
}
int main()
{
    FILE* fp = fopen("pride_and_prejudice.txt", "r");
    char buffer[MAX];
    int c = 0;
    while (fscanf(fp, "%s", buffer) != EOF)
    {
        change(strlen(buffer), buffer);
        check(buffer);
    }
    fclose(fp);
    sort();
    for (int i = 0; i < n; i += 10)
        printf("%s %d\n", word[i], count[i]);
}

