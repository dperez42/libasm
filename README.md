# LibASM

Recoding certain functions of the standard C Library, but in x86-64 Intel Assembly. (linux and MAC)

## How to use it

Using make will create the libasm.a binary. You need to have nasm.

The makefile compiles the .s (assembler file) with:

nasm -f macho64, if you use a MAC OS 64 bits.
nasm -f elf, if you use a Linux machine.

To include the library in your project, clone the repository in your working tree and compile with the following flags :

***gcc -L. -libasm main.c***

## Available functions

- size_t ft_strlen(const char *s)

- int ft_strcmp(const char *s1, const char *s2)

- char *ft_strcpy(char *dst, const char *src)

- char *ft_strdup(const char *s1);

- ssize_t ft_read(int fildes, void *buf, size_t nbyte)

- ssize_t ft_write(int fildes, const void *buf, size_t nbyte);

