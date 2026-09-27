#!/bin/bash

# Hardcoding my cross compiler
TARGET_CC="/home/jambyl/ajax_project/buildroot/output/host/bin/aarch64-linux-gcc"

$TARGET_CC -Wall -Wextra src/main.c -o app_target

if [ $? -eq 0 ]; then
    echo "[+] Succefuly compiled(cross-compiled) for TARGET: app_target"
else
    echo "[-] Error cross-compilation!"
    exit 1
fi
