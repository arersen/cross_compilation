

jambyl@DESKTOP-L6NAU1L:~/ajax_project/cross_compilation$ readelf -h app_host
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Position-Independent Executable file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x11e0
  Start of program headers:          64 (bytes into file)
  Start of section headers:          14592 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         14
  Size of section headers:           64 (bytes)
  Number of section headers:         31
  Section header string table index: 30
jambyl@DESKTOP-L6NAU1L:~/ajax_project/cross_compilation$

аналіз показує що це виконувальний файл для арх. amd64. Під  ОС UNIX - System V це є основою виконувальних файлів лінукса.


jambyl@DESKTOP-L6NAU1L:~/ajax_project/cross_compilation$ ldd app_host
        linux-vdso.so.1 (0x00007c5d6c41d000)
        libc.so.6 => /usr/lib/x86_64-linux-gnu/libc.so.6 (0x00007c5d6c000000)
        /lib64/ld-linux-x86-64.so.2 (0x00007c5d6c41f000)
jambyl@DESKTOP-L6NAU1L:~/ajax_project/cross_compilation$ size app_host
   text    data     bss     dec     hex filename
   3710     696      48    4454    1166 app_host
jambyl@DESKTOP-L6NAU1L:~/ajax_project/cross_compilation$ strings app_host | grep "System Information"
=== System Information ===
jambyl@DESKTOP-L6NAU1L:~/ajax_project/cross_compilation$
