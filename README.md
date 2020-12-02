# CTF_Campanillas_20

Para deshabilitar ASLR:

sudo bash -c 'echo 0 > /proc/sys/kernel/randomize_va_space'

Para compilar los ficheros:

gcc overflow.c -o overflow -fno-stack-protector