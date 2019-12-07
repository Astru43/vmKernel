#ifndef TTY_H
#define TTY_H

#include <stddef.h>
#include <stdint.h>

void terminal_init(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writeString(const char* str);
void terminal_putEntryAt(unsigned char ch, uint8_t color, size_t x, size_t y);
void set_terminal_color(uint8_t color);

#endif