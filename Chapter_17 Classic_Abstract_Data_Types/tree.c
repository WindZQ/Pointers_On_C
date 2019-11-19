#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "tree.h"

typedef struct TREE_NODE
{
    TREE_TYPE value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
}TreeNode;

static TreeNode *tree = NULL;

void insert(TREE_TYPE value)
{
    TreeNode *current = NULL;
    TreeNode **link   = NULL;
    link = &tree;

    while((current = *link) != NULL)
    {
        if(value < current->value)
        {
            link = &current->left;
        }
        else
        {
            assert(value != current->value);
            link = &current->right;
        }
    }

    current = malloc(sizeof(TreeNode));
    assert(current != NULL);
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    *link = current;
}

TREE_TYPE *find(TREE_TYPE value)
{
    TreeNode *current = NULL;
    current = tree;

    while(current != NULL && tree->value != value)
    {
        if(value < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if(current != NULL)
    {
        return &current->value;
    }
    else
    {
        return NULL;
    }
}

static void doPreOrderTraverse(TreeNode *current, void **callback)(TREE_TYPE value))
{
    if(current != NULL)
    {
        callback(current->value);
        doPreOrderTraverse(current->left, callback);
        doPreOrderTraverse(current->right, callback);
    }
}

void preOrderTraverse(void (*callback)(TREE_TYPE value))
{
    doPreOrderTraverse(tree, callback);
}

static void doDestroyTree(TreeNode 8current)
{
    if(current != NULL)
    {
        doDestroyTree(current->left);
        doDestroyTree(current->right);
        free(current);
        current = NULL;
    }
}

void destroyTree(void)
{
    doDestroyTree(tree);
}
