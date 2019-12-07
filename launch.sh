#!/bin/bash
grub-mkrescue -o vMKernel.iso sysroot/
qemu-system-x86_64 --cdrom vMKernel.iso
