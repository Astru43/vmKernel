#ifndef VGA_H
#define VGA_H

#include <stdint.h>

enum vga_color {
    VGA_BLACK,
    VGA_BLUE,
    VGA_GREEN,
    VGA_CYAN,
    VGA_RED,
    VGA_MAGENTA,
    VGA_BROWN,
    VGA_LIGHT_GREY,
    VGA_DARK_GREY,
    VGA_LIGHT_BLUE,
    VGA_LIGHT_GREEN,
    VGA_LIGHT_CYAN,
    VGA_LIGHT_RED,
    VGA_LIGHT_MAGENTA,
    VGA_LIGHT_BROWN,
    VGA_WHITE
};

static inline uint8_t vga_color_entry (enum vga_color fg, enum vga_color bg) {
    return fg | bg << 4;
}

static inline uint16_t vga_entry (unsigned char ch, uint8_t color) {
    return (uint16_t) ch | (uint16_t) color << 8;
}

#endif // VGA_H
