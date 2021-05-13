/*
** EPITECH PROJECT, 2020
** my_put_specials
** File description:
** Specials prints
*/

#include "my.h"
#include "stdlib.h"
#include <stdarg.h>

int my_put_octal(unsigned long int nb)
{
    int len = 0;
    char *result;
    for (int temp = nb; temp != 0;) {
        temp = temp / 8;
        len++;
    }
    result = malloc(sizeof(char) * len + 1);
    for (int i = 0; nb != 0; i++) {
        result[i] = nb % 8 + 48;
        nb = nb / 8;
    }
    my_revstr(result);
    my_putstr(result);
}

int my_put_hex(unsigned long int nb)
{
    char *result;
    int len = 0;
    int i = 0;
    for (int tmp = nb; tmp != 0;) {
        tmp = tmp / 10;
        len++;
    }
    result = malloc(sizeof(char) * len + 1);
    for (; nb != 0; i++) {
        if (nb % 16 < 10)
            result[i] = (nb % 16) + 48;
        if (nb % 16 >= 10)
            result[i] = (nb % 16) + 55;
        nb = nb / 16;
    }
    my_revstr(result);
    my_putstr(result);
    free(result);
}

int my_put_hex_low(unsigned long int nb)
{
    char *result;
    int len = 0;
    int i = 0;
    for (int tmp = nb; tmp != 0;) {
        tmp = tmp / 10;
        len++;
    }
    result = malloc(sizeof(char) * len + 1);
    for (; nb != 0; i++) {
        if (nb % 16 < 10)
            result[i] = (nb % 16) + 48;
        if (nb % 16 >= 10)
            result[i] = (nb % 16) + 87;
        nb = nb / 16;
    }
    my_revstr(result);
    my_putstr(result);
    free(result);
}

int my_put_binary(unsigned long int nb)
{
    int len = 0;
    char *result;
    for (int temp = nb; temp != 0;) {
        temp = temp / 2;
        len++;
    }
    result = malloc(sizeof(char) * len + 1);
    for (int i = 0; nb != 0; i++) {
        result[i] = nb % 2 + 48;
        nb = nb / 2;
    }
    my_revstr(result);
    my_putstr(result);
}

int my_put_pointer(unsigned long int nb)
{
    my_putstr("0x");
    my_put_hex_low(nb);
}