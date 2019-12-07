HOST=i686-elf
AR=$(HOST)-ar
CC=$(HOST)-gcc
AS=$(HOST)-as

CFLAGS?=-O2 -g -ffreestanding -Wall -Wextra
LIBK_CFLAGS:=$(CFLAGS)

CPPFLAGS:=-I "../sysroot/usr/include"
LIBK_CPPFLAGS:=$(CPPFLAGS)

OBJS= \
     string/memcmp.o \
     string/memcpy.o \
     string/memmove.o \
     string/memset.o \
     string/strlen.o \

BINARY=libk.a

LIBK_OBJS=$(OBJS:.o=.libk.o)

.PHONY: all clean install install-headers install-libs
.SUFFIXES: .o .libk.o .c .s

all: $(BINARY)

libk.a: $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 --sysroot="../sysroot" -isystem="../sysroot/usr/include" $(CFLAGS) $(CPPFLAGS)

.c.libk.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 --sysroot="../sysroot" -isystem="../sysroot/usr/include" $(LIBK_CFLAGS) $(LIBK_CPPFLAGS)

install: install-headers install-libs

install-headers: ../sysroot/usr/include/
	cp -r --preserve=timestamps string.h $<

install-libs: $(BINARY) ../sysroot/usr/lib/
	cp $(BINARY) ../sysroot/usr/lib/

../sysroot/usr/include/:
	mkdir -p $@

../sysroot/usr/lib/:
	mkdir -p $@

clean:
	-rm $(BINARY) $(OBJS)
	-rm string/*.d
	-rm $(LIBK_OBJS)
