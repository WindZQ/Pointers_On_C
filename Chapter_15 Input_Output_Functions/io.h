#ifndef _IO_H_
#define _IO_H_
int open_file(char const *filename);

void close_file();

part_number last_part_number();

part_number next_part_number();

int read_part(part_number part_number, Part *part);

void write_part(part_number part_number, Part const *part);

#endif
