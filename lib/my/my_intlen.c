/*
** EPITECH PROJECT, 2020
** my_intlen
** File description:
** Get int nb of digits
*/

int my_intlen(int nb)
{
    int i = 0;
    if (nb == 0)
        return (1);
    for (; nb != 0; i++) {
        nb = nb / 10;
    }
    return (i);
}