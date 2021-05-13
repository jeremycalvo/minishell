/*
** EPITECH PROJECT, 2020
** my_cleanstr
** File description:
** str without special char
*/

#include "my.h"
#include <stdlib.h>

char *char_to_octal(int nb)
{
    int tmp = 0;
    char *result;
    int len = 0;
    for (int temp = nb; temp != 0; len++, temp = temp / 10);
    result = malloc(sizeof(char) * len + 1);
    for (; nb != 0;) {
        tmp = (tmp * 10) + (nb % 8);
        nb = nb / 8;
    }
    for (int m = 0; tmp != 0; m++, tmp = tmp / 10) {
        result[m] = tmp % 10 + 48;
    }
    return (result);
}

int my_cleanstr(char *str)
{
    char *result;
    int m = 0;
    int p = 0;
    int n = 0;
    for (; str[m]; m++)
        if (str[m] < 32 || str[m] >= 127)
            p++;
    result = malloc(sizeof(char) * (m + p + 1));
    for (int i = 0; str[i]; i++, n++) {
        if (str[i] >= 32 || str[i] < 127)
            result[n] = str[i];
        if (str[i] < 32 || str[i] >= 127) {
            result[n++] = 92;
            my_strcat(result, char_to_octal(str[i]));
            n = my_strlen(result) - 1;
        }
    }
    result[n] = '\0';
    my_putstr(result);
    free(result);
}