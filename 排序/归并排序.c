#include <stdio.h>

#define MAXSIZE 6
int array[MAXSIZE];
void merage(int s[], int l, int mid, int r, int temp[])
{
    int i = l;
    int j = mid + 1;
    int t = 0;
    while(i <= mid && j <= r)
    {
        if(s[i] <= s[j])
        {
            temp[t++] = s[i++];
        }
        else
        {
            temp[t++] = s[j++];
        }
    }
    while(i <= mid)
    {
        temp[t++] = s[i++];
    }
    while(j <= r)
    {
        temp[t++] = s[j++];
    }
    t = 0;
    while(l <= r)
    {
      array[l++] = temp[t++];
    }
}
//分割
void spilt(int s[], int l, int r, int temp[])
{
    if(l < r)
    {
        int mid = (l + r) / 2;
        spilt(s, l , mid, temp);
        spilt(s, mid+1, r, temp);
        merage(s, l, mid, r, temp);
    }
}
//入口
void sort(int s[])
{
    int temp[MAXSIZE];
    spilt(s, 0, MAXSIZE - 1, temp);
}
int main()
{
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
    sort(array);
    printf("the rank of after sort:\n");
    for(i = 0; i < MAXSIZE; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

