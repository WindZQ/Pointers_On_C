void add_new_trans(Node *list, Node **current, Transaction *trans);
void delete_trans(Node *list, Node **current, Transaction *trans);
void search(Node *list, Node **current, Transaction *trans);
void edit(Node *list, Node **current, Transaction *trans);

void forword(Node *list, Node **current, Transaction *tran)
{
    *current = (*current)->next;
}

void backword(Node *list, Node **current, Transaction *tran)
{
    *current = (*current)->prev;
}

void (*function[])(Node *, Node **, Transaction *) =
{
    add_new_trans,
    delete_trans,
    forword,
    backword,
    search,
    edit
};

#define COUNT (sizeof(function) / sizeof(function[0]))

if(transaction->type >= NEW && transaction <= EDIT)
    function[transaction->type](list, &current, transaction);
else
    printf("Illegal transaction type!\n");
