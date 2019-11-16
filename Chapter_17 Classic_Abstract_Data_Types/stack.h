#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct ITEM
{
    int key;
    void * statellite;
} item_t;

typedef struct STACK
{
    int top;
    int size;
    item_t* array;
} stack_t;

int stack_init(stack_t * S, int size);
int stack_resize(stack_t * S, int size);
int stack_free(stack_t * S);
int stack_empty(stack_t * S);
int stack_push(stack_t * S, item_t item);
int stack_pop(stack_t * S, item_t *item);
void stack_info(stack_t * S);
#endif
