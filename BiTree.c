#include <stdio.h>
#include <stdlib.h>

typedef char TypeData;
#define MAXSIZE 100

typedef struct BiTreeNode
{
    TypeData data;
    struct BiTreeNode *lchild, *rchild;
}BITREENODE;

//创建二叉树
BITREENODE* createBiTree()
{
    char chTempData = 0;

    BITREENODE *pstNewNode = NULL;

    scanf("%c",&chTempData);
    if(chTempData == '#')
    {
        pstNewNode = NULL;
    }
    else
    {
        pstNewNode = (BITREENODE*) malloc (sizeof(BITREENODE) + 1);
        pstNewNode->data = chTempData;

        pstNewNode->lchild = createBiTree();
        pstNewNode->rchild = createBiTree();
    }

    return pstNewNode;
}
//前序
int preVisit(BITREENODE *root)
{
    if(root)
    {
        printf("%c ", root->data);

        preVisit(root->lchild);
        preVisit(root->rchild);
    }
    return 0;
}
//中序
int inVisit(BITREENODE *root)
{
    if(root)
    {
        inVisit(root->lchild);

        printf("%c ", root->data);

        inVisit(root->rchild);
    }
    return 0;
}
//后序
int postVisit(BITREENODE *root)
{
    if(root)
    {
        postVisit(root->lchild);

        postVisit(root->rchild);

        printf("%c ", root->data);
    }
    return 0;
}

int main()
{
    BITREENODE* Root;

    Root = createBiTree();

    printf("前序：");
    preVisit(Root);
    printf("\n");

    printf("中序：");
    inVisit(Root);
    printf("\n");

    printf("后序：");
    postVisit(Root);
    return 0;
}

