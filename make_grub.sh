#!/bin/bash

cat > sysroot/boot/grub/grub.cfg << EOF
menuentry "vMKernel" {
    multiboot /boot/vMKernel.bin
}
EOF