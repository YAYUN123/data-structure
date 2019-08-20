#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1
#define MAXSIZE 6
//https://blog.csdn.net/lin20044140410/article/details/79617397

typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
}SqQuene;

int InitSqQuene(SqQuene *L)
{
    L->front = 0;
    L->rear = 0;
    return OK;
}

int EnQuene(SqQuene *L, int data)
{
    if((L->rear + 1) % MAXSIZE == L->front){
        printf("队列已满。\n");
        return ERROR;
    }
    L->data[L->rear] = data;

    L->rear = (L->rear + 1) % MAXSIZE;

    return OK;
}

int DeQuene(SqQuene *L, int *data)
{
    if(L->rear == L->front){
        printf("队列为空。\n");
        return ERROR;
    }
    *data = L->data[L->front];
    L->front =  (L->front + 1) % MAXSIZE;
    return OK;
}

int printQuene(SqQuene L)
{
    if(L.rear == L.front){
        printf("队列为空。\n");
        return ERROR;
    }
    while(L.front != L.rear){
        printf("%d", L.data[L.front]);
        L.front = (L.front + 1) % MAXSIZE;
    }
    printf("\n");
    return OK;
}

int getLength(SqQuene L)
{
    int i = L.rear - L.front;
    return i;
}

int main()
{
    SqQuene L;
    int i, data_for_de;
    InitSqQuene(&L);
    printf("入队列:");
    for(i = 0; i < MAXSIZE - 1; i++)
    {
        printf("%d", i);
        EnQuene(&L, i);
    }
    printf("\n");
    printf("输出:\n");
    printQuene(L);
    DeQuene(&L, &data_for_de);
    printf("the first data:%d", data_for_de);
    printf("\n");
    printf("the length is:%d", getLength(L));
    return 0;
}
