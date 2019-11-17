#include <stdio.h>

typedef struct Tree
{
    int value;
    Tree *left;
    Tree *right;
}BTree;

int getNodeCount(BTree *root)
{
    if(NULL == root)
        return 0;
    int leftNum = getNodeCount(root->left);
    int rightNum = getNodeCount(root->right);
    int result = leftNum + rightNum + 1;
    return result;
}
