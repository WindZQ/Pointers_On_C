#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list_node.h"

int sll_remove(struct NODE **rootp, struct NODE *node)
{
    Node *p;
    assert(node != NULL);
    while((p = *rootp) != NULL)
    {
        if(p == node)
        {
            *rootp = p->link;
            free(node);
            return 1;
        }
        rootp = &p->link;
    }
    return 0;
}

int main()
{
    return 0;
}
