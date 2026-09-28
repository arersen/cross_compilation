#!/bin/bash
CURRENT_ARCH=$(uname -m)

if [ "$CURRENT_ARCH" = "aarch64" ]; then
    TARGET_CC="gcc"
    echo "[*] Started on the target ($CURRENT_ARCH). Using $TARGET_CC."
else
    TARGET_CC="/home/jambyl/ajax_project/buildroot/output/host/bin/aarch64-linux-gcc"
    echo "[*] Started on the host ($CURRENT_ARCH). Using cross-compiler."
fi

$TARGET_CC -Wall -Wextra -static src/main.c -o app_target_static

if [ $? -eq 0 ]; then
    echo "[+] Successfully compiled static: app_target_static"
else
    echo "[-] Error compilation!"
    exit 1
fi
