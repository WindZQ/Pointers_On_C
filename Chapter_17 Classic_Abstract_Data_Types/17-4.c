#include "stack.h"

int stack_init(stack_t * S, int size)
{
    S->top = 0;
    S->array = (item_t*)calloc(size, sizeof(item_t));
    if (S->array != NULL)
    {
        S->size = size;
        return 1;
    }
    else
    {
        S->size = 0;
        fprintf(stderr, "Stack init fail.\n");
        return 0;
    }
}

int stack_resize(stack_t * S, int size)
{
    S->array = (item_t*)realloc(S->array, size * sizeof(item_t));
    if (S->array != NULL)
    {
        S->size = size;
        if (S->top > S->size)
        {
            S->top = S->size;
        }
        return 1;
    }
    else
    {
        S->top = 0;
        S->size = 0;
        fprintf(stderr, "Stack resize fail.\n");
        return 0;
    }
}

int stack_free(stack_t * S)
{
    free(S->array);
    S->array = NULL;
    S->top = 0;
    S->size = 0;
    return 1;
}

int stack_empty(stack_t * S)
{
    if (S->array == NULL)
    {
        fprintf(stderr, "Stack is not initialized.\n");
        return 1;
    }
    if (S->top == 0)
        return 1;
    else
        return 0;
}

int stack_push(stack_t * S, item_t item)
{
    if (S->array == NULL)
    {
        fprintf(stderr, "Stack is not initialized.\n");
        return 0;
    }
    if (S->top < S->size)
    {
        S->array[S->top++] = item;
        return 1;
    }
    else
    {
        fprintf(stderr, "Stack overflow.\n");
        return 0;
    }
}

int stack_pop(stack_t * S, item_t * item)
{
    if (S->array == NULL)
    {
        fprintf(stderr, "Stack is not initialized.\n");
        return 0;
    }
    if (!stack_empty(S))
    {
        *item = S->array[--S->top];
        return 1;
    }
    else
    {
        fprintf(stderr, "Stack underflow\n");
        return 0;
    }
}

void stack_info(stack_t * S)
{
    static int count = 0;
    printf("%d:\n", count++);
    if (S->array == NULL)
    {
        printf("stack is not initialized.\n-------------------------------\n");
        return;
    }
    printf("stack top:%d\n", S->top);
    printf("stack size:%d\n", S->size);
    printf("stack element:\n");
    for (int i = S->top - 1; i >= 0; i--)
    {
        printf("%d ", S->array[i].key);
    }
    printf("\n-------------------------------\n");
}
