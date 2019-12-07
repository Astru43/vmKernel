
#include <vga.h>
#include <tty.h>

void kernel_entry() {
  terminal_init();

  terminal_writeString("Hello world!\n\n");
  set_terminal_color(vga_color_entry(VGA_RED, VGA_BLACK));
  terminal_writeString("  !_-_!.:.!.:.!_-_!\n\n");
  set_terminal_color(vga_color_entry(VGA_BLACK, VGA_CYAN));
  terminal_writeString("Hello world!");
}
