#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list_node.h"

int dll_insert(Node *head, Node *rear, int value)
{
    register Node *this;
    register Node *next;
    register Node *new;

    if(head != NULL)
    {
        for(this = head; (next = head->fwd) != NULL; this = next)
        {
            if(value == next->value)
                return 0;
            if(next->value > value)
                break;
        }
    }
    else
        this = next = NULL;

    new = (Node *)malloc(sizeof(Node));
    if(new == NULL)
        return -1;
    new->value = value;

    if(this == head)
        head = new;
    else
        this->fwd = new;

    if(head == NULL || next == NULL)
        rear = new;
    else
        next->fwd = new;

    new->fwd = next;
    new->bwd = this;

    return 0;
}

int main()
{
    return 0;
}
