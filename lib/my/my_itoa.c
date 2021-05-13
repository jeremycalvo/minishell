/*
** EPITECH PROJECT, 2020
** my_itoa
** File description:
** itoa
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    int len = 0;
    int neg = nb >= 0 ? 1 : -1;
    char *str;
    if (neg < 0)
        nb = nb * -1;
    for (int tmp = nb; tmp > 0; len++)
        tmp = tmp / 10;
    str = malloc(sizeof(char) * len + 1);
    if (nb == 0) {
        str[0] = '0';
        str[1] = 0;
        return (str);
    }
    str[len] = '\0';
    if (neg == 1)
        len--;
    for (; len >= 0; str[len] = nb % 10 + 48, nb = nb / 10, len--);
    if (neg == -1)
        str[0] = '-';
    return (str);
}