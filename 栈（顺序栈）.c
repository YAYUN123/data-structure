#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1
#define MAXSIZE 10
/*
https://blog.csdn.net/Cherubim1/article/details/80233752
输出乱码。。。
*/
typedef char ElemType;

typedef struct Node
{
    ElemType data[MAXSIZE];
    int top;
}Node;

typedef Node* SeqStack;

SeqStack InitSeqStack(SeqStack L)
{
    L = (SeqStack)malloc(sizeof(Node));
    L->top = 0;
    return L;
}

int PushSeqStack(SeqStack L, ElemType data)
{
    if(L->top == MAXSIZE){
        printf("满了。\n");
        return ERROR;
    }
    else{
        L->data[L->top] = data;
        L->top++;
    }
    return OK;
}

int PopSeqStack(SeqStack L, ElemType *data)
{
    if(L->top == 0){
        printf("空了。\n");
        return ERROR;
    }
    else{
        L->top--;
        *data = L->data[L->top];
    }
    return OK;
}

int printSeqStack(SeqStack L)
{
    int i = 0;
    if(L->top == 0){
        printf("空的，没有啥可以打印。\n");
        return ERROR;
    }
    for(i = 0; i < L->top+1; i++){
        printf("%c", L->data[i]);
    }
    printf("\n");
    return OK;
}

int main()
{
    SeqStack temp, L;
    int i;
    char str[50];
    ElemType char_for_pop;
    L = InitSeqStack(temp);
    printf("input the string:");
    scanf("%s", str);
    printf("the string is:");
    for(i = 0; i < strlen(str); i++)
    {
        PushSeqStack(L, str[i]);
    }
    printSeqStack(L);
    PopSeqStack(L, &char_for_pop);
    printf("pop data is:%c", char_for_pop);
    return 0;
}
