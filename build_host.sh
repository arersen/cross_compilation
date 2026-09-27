#!/bin/bash
gcc -Wall -Wextra src/main.c -o app_host

if [ $? -eq 0 ]; then
    echo "[+] Succefuly compiled: app_host"
else
    echo "[-] Error compilation!"
    exit 1
fi
