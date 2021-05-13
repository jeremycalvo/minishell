/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** lib
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int p)
{
    int i = my_strlen(dest);
    while (src[p] != '\0') {
        dest[i] = src[p];
        p++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}