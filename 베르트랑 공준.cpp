#pragma warning (disable:4996)
#include <stdio.h>
int main(void)
{
    int N, count = 0;
    int i, j, arr[246913] = { 0 };

    arr[0] = 1, arr[1] = 1;
    for (j = 2; j < 246913 / j; j++)
    {
        if (arr[j] == 1) 
            continue;
        for (i = j * j; i < 246913; i += j)
            if (i % j == 0) 
                arr[i] = 1;
    }

    while (1)
    {
        scanf("%d", &N);
        if (N == 0)
            break;
        count = 0;
        for (i = N + 1; i <= N * 2; i++)
            if (arr[i] == 0)
                count++;
        printf("%d\n", count);
    }
}