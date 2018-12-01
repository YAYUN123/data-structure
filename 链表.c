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

//ͷ�巨
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

//β�巨
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
        printf("�����ǿյġ�\n");
        *data = -1;
        return ERROR;
    }
    while(p && i < pos){
        i++;
        p = p->next;
    }
    if(p == NULL){
        printf("��ѯ�Ľڵ㳬���˱�ĳ��ȡ�\n");
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
        printf("����Ϊ�գ�Ĭ���ڵ�һ��λ�ò������ݡ�\n");
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
        printf("�����λ�ó���������ĳ��ȡ�\n");
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
        printf("�����ǿձ������ڿ���ɾ�������ݡ�\n");
        *data = -1;
        return ERROR;
    }
    while(p && pos > i){
        p = p->next;
        i++;
    }
    if(p->next == NULL){
        printf("ɾ����λ�ó���������ĳ��ȡ�\n");
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
    printf("---------��ӡ��������----------\n");
    if(p == NULL){
        printf("���Ǹ��ձ�");
        return ERROR;
    }
    while(p){
        i++;
        printf("��%d���ڵ��������:\t%d\n", i, p->data);
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
    printf("��ѯ��������:%d\n", e_for_search);

    insertListTail(L, 70);
    printList(L);

    insertList(L, 4, 100);
    printList(L);

    deleteList(L, 5, &e_for_delete);
    printf("ɾ����������:%d", e_for_delete);
    return 0;
}
