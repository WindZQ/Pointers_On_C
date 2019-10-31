#include <stdio.h>

int countNode(type *p)
{
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p->link;
    }
    return count;
}

int main()
{
    return 0;
}
