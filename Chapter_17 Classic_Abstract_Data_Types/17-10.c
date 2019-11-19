#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}TreeNode, *Btree;

Btree createTree(int *data, int pos)
{
    Btree newNode;

    if(data[pos] == 0 || pos > 15)
    {
        return NULL;
    }
    else
    {
        newNode = (Btree)malloc(sizeof(TreeNode));
        newNode->data = data[pos];
        newNode->left = createTree(data, 2 * pos);
        newNode->right = createTree(data, 2 * pos + 1);
        return newNode;
    }
}

Btree bTreeFind(Btree ptr, int value, int *pos)
{
    Btree backfather;
    backfather = ptr;
    *pos = 0;

    while(ptr != NULL)
    {
        if(ptr->data == value)
        {
            return backfather;
        }
        else
        {
            backfather = ptr;
            if(ptr->data > value)
            {
                ptr = ptr->left;
                *pos = -1;
            }
            else
            {
                ptr = ptr->right;
                *pos = 1;
            }
        }
    }
    return NULL;
}

Btree deleteNode(Btree root, int value)
{
    Btree backfather = NULL;
    Btree ptr = NULL;
    Btree next = NULL;
    int pos = 0;

    backfather = bTreeFind(root, value, &pos);
    if(backfather == NULL)
    {
        return root;
    }

    switch(pos)
    {
    case -1:
        ptr = backfather->left;
        break;
    case 0:
        ptr = backfather;
        break;
    case 1:
        ptr = backfather->right;
        break;
    default:
        break;
    }

    if(ptr->left == NULL)
    {
        if(backfather != ptr)
        {
            backfather->right = ptr->right;
        }
        else
        {
            root = root->right;
        }
        free(ptr);
        ptr = NULL;
        return root;
    }

    if(ptr->right == NULL)
    {
        if(backfather != ptr)
        {
            backfather->left = ptr->left;
        }
        else
        {
            root = root->left;
        }
        free(ptr);
        ptr = NULL;
        return root;
    }

    backfather = ptr;
    next = ptr->left;
    while(next->right != NULL)
    {
        backfather = next;
        next = next->right;
    }
    ptr->data = next->data;

    if(backfather->left == next)
    {
        backfather->left = next->left;
    }
    else
    {
        backfather->right = next->right;
    }
    free(next);
    return root;
}

void preorder(Btree ptr)
{
    if(ptr)
    {
        printf("%2d\t", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(Btree ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        printf("%2d\t", ptr->data);
        inorder(ptr->right);
    }
}

void postorder(Btree ptr)
{
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%2d\t", ptr->data);
    }
}

int main(void)
{
    Btree root = NULL;
    int value = 0;

    int data[16] = {0, 0, 5, 4, 6, 2, 0, 0, 8, 1, 3, 0, 0, 0, 0, 7, 9};
    root = createTree(data, 1);
    printf("\n-------前序遍历-------\n");
    preorder(root);
    printf("\n-------中序遍历-------\n");
    inorder(root);
    printf("\n-------后序遍历-------\n");
    postorder(root);

    printf("\n请输入想要删除的节点(1-9)：");
    scanf("%d", &value);

    root = deleteNode(root, value);
    printf("删除后树的节点内容为\n");
    printf("\n-------前序遍历-------\n");
    preorder(root);
    printf("\n-------中序遍历-------\n");
    inorder(root);
    printf("\n-------后序遍历-------\n");
    postorder(root);
    printf("\n");
    return 0;
}
