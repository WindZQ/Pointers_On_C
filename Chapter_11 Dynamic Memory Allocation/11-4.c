#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int value;
}LinkList;

int main()
{
    LinkList third  =  {NULL, 15};
    LinkList second =  {&third, 10};
    LinkList first  =  {&second, 5};
    struct node *ptr = &first;

    while(ptr != NULL)
    {
        printf("%d\t", ptr->value);
        ptr = ptr->next;
    }
    return 0;
}
