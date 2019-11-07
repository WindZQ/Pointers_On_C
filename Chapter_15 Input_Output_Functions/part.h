#ifndef _PART_H_
#define _PART_H_
#define MAX_DESCRIPTION     20
#define DESCRIPTION_FIELD_LEN (MAX_DESCRIPTION + 1)

typedef unsigned long part_number;
typedef unsigned short quantity;
typedef double value;

typedef struct
{
    char description[DESCRIPTION_FIELD_LEN];
    quantity quantity;
    value total_value;
}Part;

#define TRUE   1
#define FALSE  0
#endif
