/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** Day08 Task01
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i = my_strlen(src) + 1;
    char *str;
    str = malloc(sizeof(char) * (i));
    my_strcpy(str, src);
    return (str);
}
