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
int preVisit2(BITREENODE *root)
{
    stack<BITREENODE*> st;
    st.push(root);
    BITREENODE* tem = NULL;
    while(!st.empty())
    {
        tem = st.top();
        st.pop();
        if(tem != NULL)
        {
            printf("%c", tem->data);
            st.push(tem->lchild);
            st.push(tem->rchild);
        }
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
int inVisit2(BITREENODE *root)
{
    stack<BITREENODE*> st;
    BITREENODE *tem = root;
    do
    {
        while(tem != NULL)
        {
            st.push(tem);
            tem = tem->lchild;
        }
        tem = st.top();
        st.pop();
        printf("%c", tem->data);
        if(tem->rchild != NULL)
        {
            tem = tem->rchild;
        }
        else
        {
            tem = NULL;
        }
    }while(tem != NULL || st.empty())
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
int postVisit2(BITREENODE *root)
{
    stack<BITREENODE*> st;
    st.push(root);
    BITREENODE *tem = root;
    while(!st.empty())
    {
        BITREENODE *p = st.top();
        if(p->lchild != NULL && p->lchild != tem && p->rchild != tem)
        {
            st.push(tem->lchild);
        }
        else if(p->rchild != NULL && p->rchild != tem && (p->lchild == NULL || p->rchild == tem));
        {
            st.push(tem->rchild);
        }
        else
        {
            st.pop();
            tem = p;
            printf("%c", p->data);
        }
    }
    return 0;
}

int main()
{
    BITREENODE* Root;

    Root = createBiTree();

    printf("前序：");
    preVisit(Root);
    preVisit2(Root);
    printf("\n");

    printf("中序：");
    inVisit(Root);
    inVisit2(Root);
    printf("\n");

    printf("后序：");
    postVisit(Root);
    postVisit2(Root);
    return 0;
}

