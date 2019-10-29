#include <stdio.h>

typedef struct
{
    unsigned int    dst_reg     : 3;
    unsigned int    dst_mode    : 3;
    unsigned int    opcode      : 10;
}SingleOperat;

typedef struct
{
    unsigned int    dst_reg     : 3;
    unsigned int    dst_mode    : 3;
    unsigned int    src_reg     : 3;
    unsigned int    src_mode    : 3;
    unsigned int    opcode      : 4;
}DoubleOperat;

typedef struct
{
    unsigned int    offset      : 8;
    unsigned int    opcode      : 8;
}Branch;

typedef struct
{
    unsigned int    dst_reg     : 3;
    unsigned int    dst_mode    : 3;
    unsigned int    src_reg     : 3;
    unsigned int    opcode      : 7;
}RegistSrc;

typedef struct
{
    unsigned int    opcode      :16;
}MiscCmd;

typedef struct
{
    unsigned short  addr;
    SingleOperat    sgl_op;
    DoubleOperat    dbl_op;
    Branch          branch;
    RegistSrc       reg_src;
    MiscCmd         misc;
}machine_inst;

machine_inst    x;

int main ()
{
    return 0;
}
