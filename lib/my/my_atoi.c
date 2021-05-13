/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** my_atoi
*/

int my_atoi(char const *str)
{
    int i = 0;
    int m = 0;
    int nombre_r = 0;
    if (str[0] == '-') {
        m++;
        i++;
    }
    for (; str[m]; m++)
        if (!(str[m] >= '0' && str[m] <= '9'))
            return (0);
    for (;str[i]; i++)
        nombre_r = nombre_r * 10 + str[i] - 48;
    if (str[0] == '-')
        nombre_r = nombre_r * -1;
    return (nombre_r);
}