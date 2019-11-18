#include <stdio.h>
#define method1 0
#define method2 1
#define method3 0

struct Node
{
    int key;
    Node *left;
    Node *right;
};

#if method1
bool isBST(Node *node)
{
    if(NULL == node)
        return true;

    if(node->left != NULL && maxValue(node->left) > node->key)
        return false;
    if(node->right != NULL && maxValue(node->right) < node->key)
        return false;

    if(!isBST(node->left) || !isBST(node->right))
        return false;

    return true;
}
#endif

#if method2
bool isBSTUtil(Node * node, int min, int max)
{
    if(NULL == node)
        return true;

    if(node->key < min || node->key > max)
        return false;

    return isBSTUtil(node->left, min, node->key - 1) && isBSTUtil(node->right, node->key + 1, max);
}

bool isBST(Node *node)
{
    return (isBSTUtil(node, INT_MIN, INT_MAX));
}
#endif

#if method3
bool isBST(Node *root)
{
    static Node *prev = NULL;

    if(root)
    {
        if(!isBST(root->left))
            return false;

        if(prev != NULL && root->key <= prev->key)
            return false;
        prev = root;
        return isBST(root->right);
    }
    return true;
}
#endif


Node *createNewNode(int item )
{
        Node *temp = new Node;
       temp->key = item;
       temp->left = temp->right = NULL;
        return temp;
}


int main()
{


    Node *root = createNewNode(4);
    root->left = createNewNode(2);
    root->right = createNewNode(5);
    root->left->left = createNewNode(1);
    root->left->right = createNewNode(3);

    if (isBST(root))
    {
        printf("tree2 is BST\n");
    }
    else
    {
        printf("tree2 is not BST\n");
    }

    root = createNewNode(4);
    root->left = createNewNode(2);
    root->left->left = createNewNode(1);
    root->right = createNewNode(5);
    root->right->left = createNewNode(3);

    if (isBST(root))
    {
        printf("tree2 is BST\n");
    }
    else
    {
        printf("tree2 is not BST\n");
    }
    return 0;
}
