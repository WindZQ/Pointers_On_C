#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FIRSTNODE;

typedef struct SECONDNODE
{
    char *string;
    struct SECONDNODE *next;
}SecondNode;

typedef struct FIRSTNODE
{
    char ch;
    struct FIRSTNODE *alpha;
    struct SECONDNODE *word;
}FirstNode;

char delta[] = "abcdefghijklmnopqrstuvwxyz";

FirstNode * insert_end(FirstNode *list, char ch)
{
    FirstNode *newnode = (FirstNode *)malloc(sizeof(FirstNode));
    if(newnode == NULL)
        return NULL;
    newnode->ch = ch;
    newnode->alpha = NULL;
    newnode->word = NULL;

    if(list == NULL)
        list = newnode;
    else
    {
        FirstNode *p;
        p = list;
        while(p->alpha != NULL)
            p = p->alpha;
        p->alpha = newnode;
    }
    return list;
}

FirstNode *creat_list()
{
    int i;
    int len = strlen(delta);
    FirstNode *list = NULL;
    for(i = 0; i < len; ++i)
        list = insert_end(list, delta[i]);
    return list;
}

void print_node(FirstNode *list)
{
    FirstNode *p = list;
    while(p->alpha != NULL)
    {
        printf("%c\n", p->ch);
        if(p->word != NULL)
        {
            SecondNode *q = p->word;
            while(q != NULL)
            {
                printf("->%s\n", q->string);
                q = q->next;
            }
        }
        printf("-----------\n");
        p = p->alpha;
    }
}

int insert_word(FirstNode **listp, char *str)
{
    char c = *str;
    FirstNode *p = *listp;
    if(listp == NULL || str == NULL)
        return 0;

    while(p != NULL)
    {
        if(p->ch == c)
            break;
        p = p->alpha;
    }
    if(p == NULL)
        return 0;

    SecondNode *q = p->word;
    SecondNode *s = NULL;
    while(q != NULL)
    {
        if(strcmp(q->string, str) == 0)
            return 0;
        if(strcmp(q->string, str) > 0)
            break;
        s = q;
        q = q->next;
    }

    SecondNode *newnode = (SecondNode *)malloc(sizeof(SecondNode));
    if(newnode == NULL)
        return 0;
    newnode->string = str;

    newnode->next = q;
    if(s == NULL)
        p->word = newnode;
    else
        s->next = newnode;

    return 1;
}

int main()
{
    FirstNode *list = creat_list();
    insert_word(&list, "b2");
    insert_word(&list, "b4");
    insert_word(&list, "b1");
    insert_word(&list, "b3");
    print_node(list);
    free(list);
    return 0;
}
