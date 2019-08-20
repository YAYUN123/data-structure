#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1
#define MAXSIZE 6
//54 46 36 56 8 43
void insert_sort(int array[], int length)
{
    int i, j, temp;
    for(i = 1; i < length; i++){
        temp = array[i];
        for(j = i - 1; (j >= 0)&&(array[j] > temp); j--){
            array[j+1] = array[j];
        }
        array[j+1] = temp;
    }
}

int main()
{
    int array[MAXSIZE];
    int i;
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
    insert_sort(array, MAXSIZE);
    printf("the rank of after sort:\n");
    for(i = 0; i < MAXSIZE; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
