/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** lib
*/

#include "my.h"

void my_swaprev(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int last = my_strlen(str) - 1;
    int first = 0;

    do {
        my_swaprev(&str[first], &str[last]);
        last--;
        first++;
    } while (first < last);
    return (str);
}
