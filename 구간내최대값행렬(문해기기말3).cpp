#pragma warning (disable:4996)
#include <stdio.h>
int main()
{
    int n, data[100][100], result[100][100] = { 0 };
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &data[i][j]);


    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++)
        {
            int max = data[i][j];
            for (int k = i; k < i + 2; k++)
                for (int p = j; p < j + 2; p++)
                    if (data[k][p] > max)
                        max = data[k][p];

            result[i][j] = max;
        }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
}
