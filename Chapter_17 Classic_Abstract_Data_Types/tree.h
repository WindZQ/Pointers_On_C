#ifndef _TREE_H_
#define _TREE_H_

#define TREE_TYPE int

void insert(TREE_TYPE value);

TREE_TYPE *find(TREE_TYPE value);

void preOrderTraverse(void (*callback)(TREE_TYPE value));

void destroyTree(void);

#endif
