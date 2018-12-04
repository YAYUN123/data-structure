#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1
#define MAXSIZE 10
//https://blog.csdn.net/y6df7/article/details/81036700
typedef char ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
}node;

typedef node* Node;

typedef struct stack
{
    Node top;
    Node buttom;
}stack;

typedef stack* linkStack;

linkStack InitLinkStack(linkStack L)
{
    L = (linkStack)malloc(sizeof(stack));
    if(L == NULL){
        printf("分配内存失败。\n");
        return;
    }
    L->top = L->buttom;
    return L;
}

int PushLinkStack(linkStack L, ElemType data)
{
    Node q;
    if(L != NULL){
        q = (Node)malloc(sizeof(node));
        q->data = data;
        q->next = L->top;
        L->top = q;
    }
    return OK;
}

int PopLinkStack(linkStack L, ElemType *data)
{
    Node temp;
    if(L->top == L->buttom){
        printf("空栈，没有东西可以弹出。\n");
        return ERROR;
    }
    temp = L->top;
    *data = temp->data;
    L->top = temp->next;
    free(temp);
    return OK;
}

int printLinkStack(linkStack L)
{
    Node n;
    if(L->top == L->buttom){
        printf("空栈，没有东西可以输出。\n");
        return ERROR;
    }
    n = L->top;
    while(n != L->buttom){
        printf("%c", n->data);
        n = n->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    linkStack L, temp;
    int i;
    char str[10];
    ElemType char_for_pop;
    L = InitLinkStack(temp);
    printf("input the data:");
    scanf("%s", str);
    for(i = 0; i < strlen(str); i++)
    {
        PushLinkStack(L, str[i]);
    }
    printLinkStack(L);
    PopLinkStack(L, &char_for_pop);
    printf("pop data is:%c", char_for_pop);
    return 0;
}
