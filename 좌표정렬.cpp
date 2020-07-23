/*x,y를 구조체로 생성하고 x기준 먼저 오름차순 퀵정렬하고 x가 같은 경우에만 y기준 오름차순 퀵정렬*/
#pragma warning (disable:4996)
#include <stdio.h>
#define MAX 100000
typedef struct Array
{
    int x;
    int y;
}ARRAY;

Array array[100001];

void Swap(int a, int b)
{
    Array temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
int partitionX(int start, int end)
{
    Array pivot = array[end]; // pivot 인덱스 = end
    int left = start;
    int right = end;

    while (left < right)
    {
        while (array[left].x <= pivot.x && left < right)
        {
            // pivot 보다 큰 값을 찾을 때 까지, 이동
            ++left;
        }
        while (array[right].x >= pivot.x && left < right)
        {
            // pivot 보다 작은 값을 찾을 때 까지, 이동
            --right;
        }
        if (left < right)
        {
            Swap(left, right);
        }
    }
    Swap(right, end);

    return right;
}
void quickSortX(int start, int end)
{
    int pivot = 0;

    if (start < end)
    {
        pivot = partitionX(start, end);
        quickSortX(start, pivot - 1);
        quickSortX(pivot + 1, end);
    }
}
int partitionY(int start, int end)
{
    Array pivot = array[end]; // pivot 인덱스 = end
    int left = start;
    int right = end;

    while (left < right)
    {
        while (array[left].y <= pivot.y && left < right)
        {
            // pivot 보다 큰 값을 찾을 때 까지, 이동
            ++left;
        }
        while (array[right].y >= pivot.y && left < right)
        {
            // pivot 보다 작은 값을 찾을 때 까지, 이동
            --right;
        }
        if (left < right)
        {
            Swap(left, right);
        }
    }
    Swap(right, end);

    return right;
}
void quickSortY(int start, int end)
{
    int pivot = 0;

    if (start < end)
    {
        pivot = partitionY(start, end);
        quickSortY(start, pivot - 1);
        quickSortY(pivot + 1, end);
    }
}
int main(void)
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &array[i].x, &array[i].y);
    }

    quickSortX(0, N - 1);

    int start = 0;
    int end = N - 1;
    int cnt = 0;

    for (int i = 0; i < N - 1; i++)
    {
        while (array[i].x == array[i + 1].x)
        {
            end = i + 1;
            ++cnt;
            ++i;
        }

        // 위에서 while을 탈출 할 때, i는 어차피 다른 숫자가 나오기 전의 인덱스에 머문다.
        // 즉, 그래서 for문의 i++에 의해서 다시 다른 숫자부터 바로 시작할 수 있다.

        if (cnt >= 1)
        {
            start = end - cnt;
            quickSortY(start, end);
        }
        cnt = 0;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", array[i].x, array[i].y);
    }
}
