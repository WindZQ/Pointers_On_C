#include <stdio.h>
void print_ledger_long()
{
    printf("function print_ledger_long.\n");
}

void print_ledger_detailed()
{
    printf("function print_ledger_detailed.\n");
}

void print_ledger_default()
{
    printf("function print_ledger_default.\n");
}

void print_ledger()
{
#ifdef OPTION_LONG
    print_ledger_long();
#else
    #ifdef OPTION_DETAILED
        print_ledger_detailed();
    #else
        print_ledger_default();
    #endif
#endif
}

int main()
{
    print_ledger();
    return 0;
}
