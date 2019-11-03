#include <stdio.h>
#include "node.h"

void sll_traversal(Node *root, void (*trav)(Node *))
{
    while(root != NULL)
    {
        trav(root);
        root = root->link;
    }
}
