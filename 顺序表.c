#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define MAXSIZE 50

typedef int ElemType;

typedef struct
{
    int data[MAXSIZE];
    int length;
}SqList;

//pass
int initList(SqList *L)
{
    L->length = 0;
    printf("初始化完成。length=%d\n", L->length);
    return OK;
}
/*
随机创建 pass
int createList(SqList *L, int length)
{
    srand(time(0));
    int i;
    for(i = 0; i < length; i++){
        L->data[i] = rand()%100;
        L->length++;
    }
    return OK;
}
*/
//特定创建
//pass
int createList(SqList *L)
{
    int i;
    for(i = 0; i < 5; i++){
        L->data[i] = i+1;
        L->length++;
    }
    printf("创建完成。");
    return OK;
}

//pass
int insertList(SqList *L, int pos, ElemType elem)
{
    int i;
    if(pos < 1 || pos > L->length){
        printf("插入的位置有误，无法插入数据。\n");
        return ERROR;
    }
    for(i = L->length - 1; i >= pos-1; i--){
        L->data[i+1] = L->data[i];
    }
    L->data[pos-1] = elem;
    L->length++;
    return OK;
}

//pass
int getElem(SqList L, int pos, ElemType *e)
{
    if(pos < 1 || pos > L.length){
        printf("查找位置有误，无法获取数据。");
        *e = 9999999999;
        return ERROR;
    }
    *e = L.data[pos-1];
    return OK;
}

int locateElem(SqList L, ElemType e)
{
    int i;
    for(i = 0; i < L.length; i++){
        if(e == L.data[i]){
            printf("在pos[%d]处，找到了元素elem:%d\n", i+1, e);
            return OK;
        }
    }
    return ERROR;
}

//pass
int deleteList(SqList *L, int pos, ElemType *elem)
{
    int i;
    if(pos < 1 || pos > L->length){
        printf("删除的位置有误，无法从该位置删除数据\n");
        *elem = 99999999;
        return ERROR;
    }
    *elem = L->data[pos-1];
    for(i = pos; i < L->length; i++){
        L->data[i-1] = L->data[i];
    }
    L->length--;
    return OK;
}

int clearList(SqList *L){
    L->length = 0;
    return OK;
}

//pass
int printList(SqList L)
{
    if(L.length == 0){
        printf("表是空的。");
    }
    int i;
    for (i = 0; i < L.length; i++){
        printf("data[%d] = %d\n", i, L.data[i]);
    }
    printf("\n");
    return OK;
}

//pass
int getlength(SqList L)
{
    return L.length;
}


int main()
{
    SqList L;
    //int length = 5;
    ElemType e_for_search, e_for_delete;
    initList(&L);
    createList(&L);
    printList(L);

    getElem(L, 3, &e_for_search);
    printf("对应位置的元素:%d\n", e_for_search);

    printf("表的长度:%d\n", getlength(L));

    insertList(&L, 3, 10);//插入到第三个位置
    printList(L);

    deleteList(&L, 3, &e_for_delete);
    printf("对应位置删除的元素是:%d\n", e_for_delete);
    printList(L);

    locateElem(L, 4);

    clearList(&L);
    printList(L);
    return 0;
}
