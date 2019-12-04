#ifndef TTY_H
#define TTY_H

#include <stddef.h>

void terminal_init(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writeString(const char* str);

#endif