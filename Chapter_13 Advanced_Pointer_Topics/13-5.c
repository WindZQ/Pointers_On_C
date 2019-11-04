#include <stdio.h>
#include <stdlib.h>

enum {NONE, FLAG, ARG};

argtype(register int ch, register int *control)
{
    while(*control != '\0')
    {
        if(ch == *control++)
            return *control == '+' ? ARG : FLAG;
    }
    return NONE;
}

char **do_args(int argc, char **argv, char *control, void (*do_args)(int ch, char *value), void (*illegal_arg)(int ch))
{
    register char *argp;
    register int ch;
    register int skip_arg;

    while((argp = *++argv) != NULL && *argp == '-')
    {
        skip_arg = 0;
        while(!skip_arg && (ch = *++argp) != '\0')
        {
            switch(argtype(ch, control))
            {
            case FLAG:
                (*do_args)(ch, NULL);
                break;
            case ARG:
                if(*++argp != '\0' || (argp == *argv) != NULL)
                {
                    (*do_args)(ch, argp);
                    skip_arg = 1;
                    break;
                }
                (*illegal_arg)(ch);
                return argv;
            case NONE:
                (*illegal_arg)(ch);
                break;
            }
        }
    }
    return argv;
}

