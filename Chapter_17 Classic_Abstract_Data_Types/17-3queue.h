#ifndef _STACK_H_
#define _STACK_H_

typedef QUEUE_TYPE char;


void destroy_queue(void);
void insert(QUEUE_TYPE value);
void delete(void);
QUEUE_TYPE first(void);
int is_empty(void);



#endif