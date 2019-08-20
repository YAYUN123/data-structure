#include <stdio.h>

#define MAXSIZE 5

void adjustHeap(int s[], int a)
{
    int temp = s[a], k;
    for(k = a * 2 + 1; k < MAXSIZE; k = 2 * k + 1)
    {
        if(k + 1 < MAXSIZE && s[k] < s[k+1])
        {
            k++;
        }
        if(s[k] > temp)
        {
            s[a] = s[k];
            a = k;
        }
        else
        {
            break;
        }
    }
    s[a] = temp;
}


void swarp(int s[], int a, int b)
{
   int temp = s[a];
   s[a] = s[b];
   s[b] = temp;
}

void sort(int s[])
{
    int i, j;
    for(i = MAXSIZE / 2 - 1; i >= 0; i--)
    {
        adjustHeap(s, i);
    }
    for(j = MAXSIZE - 1; j > 0; j--)
    {
        swarp(s, 0, j);
        adjustHeap(s, 0);
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
    sort(array);
    printf("the rank of after sort:\n");
    for(i = 0; i < MAXSIZE; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

