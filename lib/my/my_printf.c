/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>

int my_format_plus(char *str, int i, va_list parameters)
{
    int nb;
    char c = str[i + 2];
    if (c == 'd' || c == 'i')
        nb = va_arg(parameters, int);
        if (nb >= 0) {
            my_putchar('+');
            my_put_nbr(nb);
        }

    return (str[i + 1]);
}

int my_format_hashtag(char *str, int i, va_list parameters)
{
    char c = str[i + 2];
    if (c == 'o') {
        my_putchar('0');
        my_put_octal(va_arg(parameters, unsigned long int));
    }
    if (c == 'x') {
        my_putstr("0x");
        my_put_hex_low(va_arg(parameters, unsigned long int));
    }
    if (c == 'X') {
        my_putstr("0X");
        my_put_hex(va_arg(parameters, unsigned long int));
    }
    return (str[i + 1]);
}

int choose_arg(char *str, int i, va_list parameters)
{
    char c = str[i + 1];
    if (c >= '0' && c <= '9') {
        i = my_format(str, i + 1, parameters);
        c = str[i];
    }
    (c == 'd' || c == 'i') && my_put_nbr(va_arg(parameters, int));
    (c == 'u') && my_put_unsigned_nbr(va_arg(parameters, unsigned int));
    (c == 's') && my_putstr(va_arg(parameters, char *));
    (c == 'S') && my_cleanstr(va_arg(parameters, char *));
    (c == 'o') && my_put_octal(va_arg(parameters, unsigned long int));
    (c == 'c') && my_putchar(va_arg(parameters, int));
    (c == 'b') && my_put_binary(va_arg(parameters, unsigned long int));
    (c == 'p') && my_put_pointer(va_arg(parameters, unsigned long int));
    (c == '%') && my_putchar('%');
    (c == '+') && (c = my_format_plus(str, i, parameters)) && i++;
    (c == '#') && (c = my_format_hashtag(str, i, parameters)) && i++;
    !(is_char_in_str(c, "+#0123456789diusSopcXxb%")) \
    && my_putchar('%') && my_putchar(c);
    return (i);
}

int my_printf(char *str, ...)
{
    va_list parameters;
    va_start(parameters, str);
    for (int i = 0; str[i];) {
        if (str[i] != '%') {
            my_putchar(str[i]);
            i++;
        }
        if (str[i] == '%') {
            i = choose_arg(str, i, parameters);
            i += 2;
        }
    }
    va_end(parameters);
    return (my_strlen(str));
}