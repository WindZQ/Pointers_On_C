#include <stdio.h>
#include <stdlib.h>
#include "part.h"
#include "io.h"
#include "process.h"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage :inventory inv-filename.\n");
        return -1;
    }
    if(open_file(argv[1]))
    {
        while(process_request())
            ;
        close_file();
    }
    return 0;
}
