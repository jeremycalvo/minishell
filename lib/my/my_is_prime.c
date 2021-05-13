/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** lib
*/

int reste(int nb, int i)
{
    while (i != nb) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int my_is_prime(int nb)
{
    int i = 2;

    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (0);
    if (nb == 2)
        return (1);
    if (nb > 2) {
        return (reste(nb, i));
    }
}
