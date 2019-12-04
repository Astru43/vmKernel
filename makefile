
OBJS=\
kernel.o \
boot.o \
tty.o

HOST=i686-elf
AR=$(HOST)-ar
CC=$(HOST)-gcc
AS=$(HOST)-as

CFLAGS?=-O2 -g
CPPFLAGS?=
LDFLAGS?=
LIBS?=

CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra
CPPFLAGS:=$(CPPFLAGS) -D__is_kernel -Iinclude
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

.PHONY: all clean install install-headers install-kernel
.SUFFIXES: .o .c .s

all: vMKernel.bin

vMKernel.bin: $(OBJS) linker.ld

.c.o: install-headers
	$(CC) -MD -c $< -o $@ -std=gnu11 \
	--sysroot="$(pwd)/sysroot" \
	-isystem="/usr/include" $(CFLAGS) $(CPPFLAGS)

.s.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

sysroot/usr/include/:
	mkdir -p $@

clean:
	rm -f $(OBJS) *.o */*.o
	rm -f vMKernel.bin
	rm -rf sysroot/boot/

install: install-headers install-kernel

install-headers: sysroot/usr/include/
	cp -r --preserve=timestamps include/. $<.

install-kernel: vMKernel.bin
	mkdir -p sysroot/boot/grub/
	cp $< sysroot/boot/.
	. ./make_grub.sh