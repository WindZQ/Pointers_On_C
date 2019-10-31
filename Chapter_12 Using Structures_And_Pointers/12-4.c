#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list_node.h"

struct NODE *sll_reverse(struct NODE *first)
{
    Node *current;
    Node *next;

    if(first != NULL)
    {
        for(current = NULL; first != NULL; first = next)
        {
            next = first->link;
            first->link = current;
            current = first;
        }
    }
    return first;
}

int main()
{
    return 0;
}
