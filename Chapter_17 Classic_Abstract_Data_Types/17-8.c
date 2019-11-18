#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int flag = 0;
typedef struct bitnode
{
    int data;
    struct bitnode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree Initiate()
{
    BiTNode *bt;
    bt = (BiTNode*)malloc(sizeof(BiTNode));
    if(bt == NULL) return NULL;
    bt->lchild = NULL;
    bt->rchild = NULL;
    return bt;
}

BiTree Create(int x,BiTree lbt,BiTree rbt)
{
    BiTree p;
    if((p = (BiTNode*)malloc(sizeof(BiTNode))) == NULL)
        return NULL;
    p->data = x;
    p->lchild = lbt;
    p->rchild = rbt;
    return p;
}

BiTree InsertL(BiTree bt,int x,BiTree parent)
{
    BiTree p;
    if(parent == NULL)
    {
        printf("为空树，无法进行插入工作");
        return NULL;
    }
    if((p = (BiTNode*)malloc(sizeof(BiTNode))) == NULL) return NULL;
    p->data = x;
    p->lchild = NULL;
    p->rchild = NULL;
    if(parent->lchild==NULL)
        parent->lchild = p;
    else
    {
        p->lchild  = parent->lchild;
        parent->lchild = p;
    }
    return bt;
}

BiTree InsertR(BiTree bt,int x,BiTree parent)
{
    BiTree p;
    if(parent == NULL)
    {
        printf("为空树，无法进行插入工作");
        return NULL;
    }
    if((p = (BiTNode*)malloc(sizeof(BiTNode))) == NULL) return NULL;
    p->data=x;
    p->lchild=NULL;
    p->rchild=NULL;
    if(parent->rchild==NULL)
        parent->rchild = p;
    else
    {
        p->rchild = parent->rchild;
        parent->rchild = p;
    }
    return bt;
}

BiTree DelectL(BiTree bt,BiTree parent)
{
    BiTree p;
    if(parent == NULL||parent->lchild == NULL)
    {
        printf("parent为空或者左子树为空！无法删除！");
        return NULL;
    }
    p = parent->lchild;
    parent->lchild = NULL;
    free(p);
    printf("删除成功！\n");
    return bt;
}

BiTree DelectR(BiTree bt,BiTree parent)
{
    BiTree p;
    if(parent == NULL||parent->rchild == NULL)
    {
        printf("parent为空或者右子树为空！无法删除！");
        return NULL;
    }
    p = parent->rchild;
    parent->rchild = NULL;
    free(p);
    printf("删除成功！\n");
    return bt;
}

void PreOrder(BiTree bt)
{
    if(bt == NULL) return;
    printf("%d ",bt->data);
    PreOrder(bt->lchild);
    PreOrder(bt->rchild);
}

void InOrder(BiTree bt)
{
    if(bt == NULL) return;
    InOrder(bt->lchild);
    printf("%d ",bt->data);
    InOrder(bt->rchild);
}

void PostOrder(BiTree bt)
{
    if(bt == NULL) return;
    PostOrder(bt->lchild);
    PostOrder(bt->rchild);
    printf("%d ",bt->data);
};

void list()
{
    printf("1.初始化\t\t");
    printf("2.创建一棵二叉树\n");
    printf("3.左子树插入\t\t");
    printf("4.右子树插入\n");
    printf("5.删除左子树\t\t");
    printf("6.删除右子树\n");
    printf("7.先序遍历\t\t");
    printf("8.中序遍历\n");
    printf("9.后序遍历\t\t");
    printf("10.退出\n\n");
}

int main(void)
{
    int c;
    int x;
    while(true)
    {
        list();
        printf("请选择功能：");
        scanf("%d",&c);
        if(c >= 10) break;
        switch(c)
        {
            case 1:
                BiTree bt,p;
                bt = Initiate();
                if(bt == NULL)
                    printf("初始化失败!\n");
                else
                    printf("初始化成功（带头结点）！\n");
                break;
            case 2:
                printf("请输入根结点的数据：");
                scanf("%d",&x);
                p = Create(x,NULL,NULL);
                if(p != NULL)
                {
                    bt->lchild = p;
                    printf("创建成功！\n",p->data);
                }
                else
                {
                    printf("创建失败!\n");
                }
                break;
            case 3:
                printf("请输入要插入的数据：");
                scanf("%d",&x);
                p = InsertL(bt,x,bt->lchild);
                if(p != NULL)
                {
                    printf("插入成功！\n");
                }
                else
                    printf("插入失败！\n");
                break;
            case 4:
                printf("请输入要插入的数据：");
                scanf("%d",&x);
                p = InsertR(bt,x,bt->lchild);
                if(p != NULL)
                {
                    printf("插入成功！\n");
                }
                else
                    printf("插入失败！\n");
                break;
            case 5:
                DelectL(bt,bt->lchild);
                break;
            case 6:
                DelectR(bt,bt->lchild);
                break;
            case 7:
                PreOrder(bt->lchild);
                break;
            case 8:
                InOrder(bt->lchild);
                break;
            case 9:
                PostOrder(bt->lchild);
                break;
            default:
                break;
        }
        printf("\n\n");
    }
}
