#include <stdio.h>
#include "cpu_type.h"

int cpu_type()
{
#ifdef VAX
    return CPU_VAX;
#elif M68000
    return CPU_68000;
#elif M68020
    return CPU_68020;
#elif I80386
    return CPU_80386;
#elif X6809
    return CPU_6809;
#elif X6502
    return CPU_6502;
#elif U3B2
    return CPU_3B2;
#else
    return CPU_UNKNOWN;
#endif
}

int main()
{
    printf("%d\n", cpu_type());
    return 0;
}
