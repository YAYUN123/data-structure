#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1
#define MAXSIZE 10

void print_array(int *ary, int len)
{
    int i = 0;
    while(i < len){
        printf("%d ", ary[i++]);
    }
    printf("\n");
}

void shell_sort(int *ary, int len)
{
    int i, j, increment = len, key;
    while(increment > 1){
        increment = increment / 3 + 1;
        //printf("the increment is: %d\n", increment);
        for(i = increment; i < len; i++){
            j = i - increment;
            while(j >= 0){
                if(ary[i] > ary[j]){
                    int temp = ary[i];
                    ary[i] = ary[j];
                    ary[j] = temp;
                }
                j = j - increment;
            }
        }
    }
}

int main()
{
    int ary[MAXSIZE] = {9, 1, 5, 8, 3, 7, 6, 0, 2, 4};
    printf("the sort before:\n");
    print_array(ary, MAXSIZE);
    shell_sort(ary, MAXSIZE);
    printf("the sort after:\n");
    print_array(ary, MAXSIZE);
    return 0;
}
