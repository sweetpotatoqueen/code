#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
	int year, month, day, hour, minute, second;
} MyDate;
MyDate dates[MAX];
int read_line(char str[], int limit)
{
	int ch, i = 0;
	while ((ch = getchar()) != '\n')
		if (i < limit - 1)
			str[i++] = ch;

	str[i] = '\0';

	return i;
}
int month_(char* mon) { //char->int
    if (strcmp(mon, "Jan") == 0)
        return 1;
    else if (strcmp(mon, "Feb") == 0)
        return 2;
    else if (strcmp(mon, "Mar") == 0)
        return 3;
    else if (strcmp(mon, "Apl") == 0)
        return 4;
    else if (strcmp(mon, "May") == 0)
        return 5;
    else if (strcmp(mon, "Jun") == 0)
        return 6;
    else if (strcmp(mon, "Jul") == 0)
        return 7;
    else if (strcmp(mon, "Aug") == 0)
        return 8;
    else if (strcmp(mon, "Sep") == 0)
        return 9;
    else if (strcmp(mon, "Oct") == 0)
        return 10;
    else if (strcmp(mon, "Nov") == 0)
        return 11;
    else if (strcmp(mon, "Dec") == 0)
        return 12;
    else
        return 0;
}
void divide(char str[], int i) {
    char division[] = "[]/:";
    char* token;
    token = strtok(str, division);
    dates[i].day = atoi(token);
    token = strtok(NULL, division);
    dates[i].month = month_(token);
    token = strtok(NULL, division);
    dates[i].year = atoi(token);
    token = strtok(NULL, division);
    dates[i].hour = atoi(token);
    token = strtok(NULL, division);
    dates[i].minute = atoi(token);
    token = strtok(NULL, division);
    dates[i].second = atoi(token);
}

void swap(MyDate* a, MyDate* b) {
    MyDate tmp = *a;
    *a = *b;
    *b = tmp;
}


void sort(int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (dates[j].year > dates[j + 1].year) {
                swap(&dates[j], &dates[j + 1]);
            }
            else if (dates[j].year == dates[j + 1].year && dates[j].month > dates[j + 1].month) {
                swap(&dates[j], &dates[j + 1]);
            }
            else if (dates[j].year == dates[j + 1].year && dates[j].month == dates[j + 1].month && dates[j].day > dates[j + 1].day)
                swap(&dates[j], &dates[j + 1]);
            else if (dates[j].year == dates[j + 1].year && dates[j].month == dates[j + 1].month && dates[j].day == dates[j + 1].day && dates[j].hour > dates[j + 1].hour)
                swap(&dates[j], &dates[j + 1]);
            else if (dates[j].year == dates[j + 1].year && dates[j].month == dates[j + 1].month && dates[j].day == dates[j + 1].day && dates[j].hour == dates[j + 1].hour && dates[j].minute > dates[j + 1].minute)
                swap(&dates[j], &dates[j + 1]);
            else if (dates[j].year == dates[j + 1].year && dates[j].month == dates[j + 1].month && dates[j].day == dates[j + 1].day && dates[j].hour == dates[j + 1].hour && dates[j].minute == dates[j + 1].minute && dates[j].second > dates[j + 1].second)
                swap(&dates[j], &dates[j + 1]);

        }
    }
}
    void print(int i) {
        printf("%d-%02d-%02d:%02d:%02d:%02d\n", dates[i].year, dates[i].month, dates[i].day, dates[i].hour, dates[i].minute, dates[i].second);
    }

    int main() {
        int n;
        char data[MAX];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            if (read_line(data, MAX) <= 0)
                continue;
            divide(data, i);
        }
        sort(n);
        for (int i = 0; i < n; i++)
            print(i);
    }
