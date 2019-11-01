#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "doubly_linked_list_node.h"

int dll_remove(struct NODE *rootp, struct NODE *node)
{
    Node *p;
    assert(node != NULL);
    while((p = rootp->fwd) != NULL)
    {
        if(p == node)
        {
            if(p->bwd == NULL)
                rootp->fwd = p->fwd;
            else
                p->fwd->bwd = p->fwd;

            if(p->fwd != NULL)
                p->fwd->bwd = rootp;
            else
                rootp->bwd = p->bwd;
            free(node);
            return 1;
        }
        rootp = p;
    }
    return 0;
}

int main()
{
    return 0;
}
