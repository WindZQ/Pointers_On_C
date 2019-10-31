#include <stdio.h>
#include "singyl_linked_list_node.h"

Node *search(Node *head, type value)
{
    Node *p = head;
    while(p != NULL)
    {
        if(p->data == value)
            break;
        p = p->link;
    }
    return p;
}

int main()
{
    return 0;
}
