#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

typedef Node* linkList;

//头插法
linkList createListHead(int n)
{
    linkList head = (linkList)malloc(sizeof(Node));
    head->next = NULL;
    linkList p;
    int i = 0;

    for(i = 0; i < n; i++){
        p = (linkList)malloc(sizeof(Node));
        p->data = (i+1) * 10;
        p->next = head->next;
        head->next = p;
    }
    return head;
}

//尾插法
linkList createListTail(int n)
{
    linkList head, temp, p;
    int i = 0;
    head = (linkList)malloc(sizeof(Node));
    temp = head;
    for(i = 0; i < n; i++){
        p = (linkList)malloc(sizeof(Node));
        p->data = (i+1) * 10;
        temp->next = p;
        temp = p;
    }
    temp->next = NULL;
    return head;
}

//pass
int getElem(linkList L, int pos, ElemType *data)
{
    linkList p;
    int i = 1;
    p = L->next;
    if(p == NULL){
        printf("链表是空的。\n");
        *data = -1;
        return ERROR;
    }
    while(p && i < pos){
        i++;
        p = p->next;
    }
    if(p == NULL){
        printf("查询的节点超出了表的长度。\n");
    }
    *data = p->data;
    return OK;
}

int insertList(linkList L, int pos, ElemType data)
{
    linkList p, temp,insert_node;
    int i = 1;
    temp = L;
    p = L;
    if(p->next == NULL){
        printf("链表为空，默认在第一个位置插入数据。\n");
        insert_node = (linkList)malloc(sizeof(Node));
        insert_node->data = data;
        temp->next = insert_node;
        temp = insert_node;
    }
    while(p && pos > i){
        p = p->next;
        i++;
    }
    if(p->next == NULL){
        printf("插入的位置超过了链表的长度。\n");
        return ERROR;
    }
    insert_node = (linkList)malloc(sizeof(Node));
    insert_node->data = data;
    insert_node->next = p->next;
    p->next = insert_node;
    return OK;
}

int insertListTail(linkList L, ElemType data)
{
    linkList p, temp;
    while(p){
        temp = p;
        p = p->next;
    }
    p = (linkList)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    temp->next = p;
    return OK;
}

int deleteList(linkList L, int pos, ElemType *data)
{
    linkList p, pnext;
    int i = 1;
    p = L;
    if(p->next == NULL){
        printf("链表是空表，不存在可以删除的数据。\n");
        *data = -1;
        return ERROR;
    }
    while(p && pos > i){
        p = p->next;
        i++;
    }
    if(p->next == NULL){
        printf("删除的位置超过了链表的长度。\n");
        *data = -1;
        return ERROR;
    }
    pnext = p->next;
    p->next = pnext->next;
    *data = pnext->data;
    free(pnext);
    return OK;
}

int clearList(linkList L)
{
    linkList p, temp;
    p = L->next;
    while(p){
        temp = p;
        p = p->next;
        free(temp);
    }
    L->next = NULL;
    return OK;
}

//pass
int getlength(linkList L)
{
    linkList p = NULL;
    int length = 0;
    p = L->next;
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

//pass
int printList(linkList L)
{
    int i = 0;
    linkList p = NULL;
    p = L->next;
    printf("---------打印整个链表----------\n");
    if(p == NULL){
        printf("这是个空表。");
        return ERROR;
    }
    while(p){
        i++;
        printf("第%d个节点的数据是:\t%d\n", i, p->data);
        p = p->next;
    }
    return OK;
}

int main()
{
    linkList L = NULL;
    ElemType e_for_search, e_for_delete;
    int n = 6;
    //L = createListHead(n);
    L = createListTail(n);

    printList(L);
    printf("the length is:%d\n", getlength(L));
    int locate = 3;
    getElem(L, locate, &e_for_search);
    printf("查询的数据是:%d\n", e_for_search);

    insertListTail(L, 70);
    printList(L);

    insertList(L, 4, 100);
    printList(L);

    deleteList(L, 5, &e_for_delete);
    printf("删除的数据是:%d", e_for_delete);
    return 0;
}
