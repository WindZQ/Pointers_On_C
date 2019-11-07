#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "part.h"
#include "io.h"

static FILE        *inv_file;
static part_number part_number[2];
static enum        {LAST, NEXT};

static void write_part_numbers()
{
    fseek(inv_file, 0, SEEK_SET);
    fwrite(part_number, sizeof(part_number), 2, inv_file);
}

int open_file(char const *filename)
{
    inv_file = fopen(filename, "rb+");
    if(inv_file == NULL)
    {
        if(errno == ENOENT)
        {
            inv_file = fopen(filename, "wb+");
            if(inv_file != NULL)
            {
                part_number[LAST] = 0;
                part_number[NEXT] = 1;
                write_part_numbers();
            }
        }
        if(inv_file == NULL)
            perror(filename);
    }
    else
        fread(part_number, sizeof(part_number), 2, inv_file);
    return inv_file != NULL;
}

void close_file()
{
    fclose(inv_file);
}

part_number last_part_number()
{
    return part_number[LAST];
}

part_number next_part_number()
{
    Part part;
    while(part_number[NEXT] <= part_number[LAST])
    {
        if(!read_part(part_number[NEXT], &part))
            break;
        part_number[NEXT] += 1;
    }
    write_part_numbers();
    return part_number[NEXT];
}

int read_part(part_number p, Part &part)
{
    if(p > 0 && p <= part_number[LAST])
    {
        fseek(inv_file, p * sizeof(Part), SEEK_SET);
        if(fread(part, sizeof(Part), 1, inv_file) != 1)
            perror("Cannot read part!");
        return *part->description != '\0';
    }
    return FALSE;
}

void write_part(part_number p, Part const *part)
{
    if(p > 0 && p <= part_number[LAST] + 1)
    {
        fseek(inv_file, p * sizeof(Part), SEEK_SET);
        if(fwrite(part, sizeof(Part), 1, inv_file) != 1)
        {
            perror("Cannot write part!");
            exit(0);
        }
        if(p > part_number[LAST])
        {
            part_number[LAST] = p;
            write_part_numbers();
        }
        if(part->description[0] == '\0' && p < part_number[NEXT])
        {
            part_number[NEXT] = p;
            write_part_numbers();
        }
    }
}
