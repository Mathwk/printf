#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

int print_str(char *str, int p_index);
int _printf(const char *format, ...);
int conv_spec(const char *format, int index, va_list ap);
int pr_char(va_list(ap));
int pr_string(va_list(ap));
int pr_percent(va_list(ap));
int pr_int(va_list(ap));
int pr_binary(va_list(ap));
int pr_unsigned(va_list(ap));
int pr_octal(va_list(ap));
int pr_hexad(va_list(ap));
int pr_hexaD(va_list(ap));
int pr_address(va_list(ap));

/**
 * struct sp - structure for function selection
 * @sp: conversion specifier
 * @fn: function to be called
 */
typedef struct sp
{
char sp;
int (*fn)(va_list);
} sp_t;

#endif /* MAIN_H */
