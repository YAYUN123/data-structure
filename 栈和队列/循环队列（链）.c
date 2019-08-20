#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1
#define MAXSIZE 6
//https://blog.csdn.net/lin20044140410/article/details/79617397

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef node* Node;

typedef struct Quene
{
    Node front;
    Node rear;
}Quene;

typedef Quene* linkQuene;

linkQuene InitLinkQuene(linkQuene L)
{
    L = (linkQuene)malloc(sizeof(Quene));
    if(L == NULL){
        printf("分配内存失败。\n");
        return ERROR;
    }
    L->front = L->rear = (Node)malloc(sizeof(node));
    if(L->front == NULL){
        printf("分配内存失败。\n");
        return ERROR;
    }
    L->front->next = NULL;
    return L;
}

int EnQuene(linkQuene L, int data)
{
    Node node = (Node)malloc(sizeof(node));
    if(node == NULL){
        printf("内存分配失败。不能插入\n");
        return ERROR;
    }
    node->data = data;
    node->next = NULL;
    L->rear->next = node;
    L->rear = node;
    return OK;
}

int DeQuene(linkQuene L, int *data)
{
    Node node;
    if(L->front == L->rear){
        printf("空了。\n");
        return ERROR;
    }
    node = L->front->next;
    *data = node->data;
    L->front->next = node->next;
    free(node);
    if(L->rear == node){
        L->rear = L->front;
    }
    free(node);
    return OK;
}

int printLinkQuene(linkQuene L)
{
    Node node;
    if(L->front == L->rear){
        printf("空的。\n");
        return ERROR;
    }
    node = L->front->next;
    while(node != NULL){
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
    return OK;
}

int DestoryQuene(linkQuene L)
{
    while(L->front){
        L->rear = L->front->next;
        free(L->front);
        L->front = L->rear;
    }
    return OK;
}

int ClearLinkQuene(linkQuene L)
{
    Node p, q;
    L->front = L->rear;
    p = L->front->next;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

int getLength(linkQuene L)
{
    int i = 0;
    Node p = L->front;
    while(L->rear != p)
    {
        p = p->next;
        i++;
    }
    return i;
}


int main()
{
    int i, data_for_de, length;
    linkQuene L, temp;
    L = InitLinkQuene(temp);
    for(i = 0; i < MAXSIZE; i++)
    {
        EnQuene(L, i);
    }
    printLinkQuene(L);
    DeQuene(L, &data_for_de);
    printf("the delete data is:%d\n", data_for_de);
    length = getLength(L);
    printf("the length is:%d", length);
    return 0;
}
