/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** lib
*/

#include "my.h"

int my_isneg(int nb)
{
    if (nb < 0) {
        my_putchar(78);
    }
    else {
        my_putchar(80);
    }
    my_putchar(10);
}
