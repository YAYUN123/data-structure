#include <stdio.h>

#define MAXSIZE 6
void SelectSort(int s[])
{
    int i, j;
    for(i = 0; i < MAXSIZE - 1; i++)
    {
        int minIndex = i;
        for(j = i+1; j < MAXSIZE; j++)
        {
            minIndex = s[minIndex] < s[j] ? minIndex : j;
        }
        int temp = s[i];
        s[i] = s[minIndex];
        s[minIndex] = temp;
    }
}
int main()
{
    int array[MAXSIZE], i;
    printf("Input %d numbers: \n", MAXSIZE);
    for(i = 0; i < MAXSIZE; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("the rank of before sort:\n");
    for(i = 0; i < MAXSIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    SelectSort(array);
    printf("the rank of after sort:\n");
    for(i = 0; i < MAXSIZE; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

