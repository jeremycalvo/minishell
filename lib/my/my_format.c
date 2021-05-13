/*
** EPITECH PROJECT, 2020
** my_format
** File description:
** Format
*/

#include "my.h"
#include <stdarg.h>

int my_format(char *str, int i, va_list parameters)
{
    int arg_int = 0;
    char *arg_str;
    int len = 0;
    int nb = my_getnnbr(str, i);
    for (; str[i] >= '0' && str[i] <= '9'; i++);
    if (is_char_in_str(str[i], "diouxX")) {
        arg_int = va_arg(parameters, int);
        len = my_intlen(arg_int);
        for (; nb - len > 0; len++)
            my_putchar(' ');
    }
    (str[i] == 'c') && (my_putchar(va_arg(parameters, int)));
    if (is_char_in_str(str[i], "sS")) {
        arg_str = va_arg(parameters, char *);
        len = my_strlen(arg_str);
        for (; nb - len > 0; len++, my_putchar(' '));
        my_putstr(arg_str);
    }
    (is_char_in_str(str[i], "diouxX")) && my_formated_print(str[i], arg_int);
    return (i - 1);
}

int my_formated_print(char c, int nb)
{
    (c == 'd' || c == 'i') && my_put_nbr(nb);
    (c == 'u') && my_put_unsigned_nbr(nb);
    (c == 'o') && my_put_octal(nb);
    (c == 'X') && my_put_hex(nb);
    (c == 'x') && my_put_hex_low(nb);
}