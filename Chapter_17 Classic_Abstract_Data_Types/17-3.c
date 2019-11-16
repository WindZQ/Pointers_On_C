#include <stdio.h>
#include <assert.h>
#include "17-3queue.h"

typedef struct QUEUE_NODE
{
    QUEUE_TYPE value;
    struct QUEUE_NODE *next;
}QueueNode;

static QueueNode *front;
static QueueNode *rear;

void destroy_queue(void)
{
    while(!is_empty())
        delete();
}

void insert(QUEUE_TYPE value)
{
    QueueNode *new_node = NULL;
    new_node = (QueueNode *)malloc(sizeof(QueueNode));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->next = NULL;

    if(NULL == rear)
    {
        front = new_node;
    }
    else
    {
        rear->next = new_node;
    }
    rear = new_node;
}

void delete(void)
{
    QueueNode *next_node;
    assert(!is_empty());
    next_node = front->next;
    free(front);
    front = next_node;
    if(NULL == front)
    {
        rear = NULL;
    }
}

QUEUE_TYPE first(void)
{
    assert(!is_empty());
    return front->value;
}

int is_empty(void)
{
    return front == NULL;
}
