#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void printValue(TREE_TYPE value)
{
    printf("%d\t", value);
}

int main(void)
{
    int i = 0, value = 0, *ret = NULL;

    for(i = 0; i < 6; ++i)
    {
        printf("value:");
        scanf("%d", &value);
        insert(value);
    }
    printf("\n");

    preOrderTraverse(printValue);
    printf("\n");

    for(i = 0; i < 3; ++i)
    {
        printf("find value:");
        scanf("%d", &value);
        ret = find(value);
        if(NULL == ret)
        {
            printf("not found!\n");
        }
        else
        {
            printf("ok, value:%d\n", *ret);
        }
    }
    destroyTree();

    return 0;
}
