#include <stdio.h>

void breadthFirstTraversal(void (callback)(TREE_TYPE value))
{
    int current = 0, child = 0;
    queue_insert(1);
    while(!is_queue_empty())
    {
        current = queue_first();
        queue_delete();
        callback(tree(current));

        child = left_child(current);
        if(child < ARRAY_SIZE && tree[child] != 0)
            queue_insert(child);
        child = left_child(current);
        if(child < ARRAY_SIZE && tree[child] != 0)
            queue_insert(child);
    }
}
