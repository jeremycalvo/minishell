/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Day04 Task05
*/

int is_neg(char a)
{
    if (a == '-')
        return (-1);
    else
        return (1);
}

int my_getnbr(char const *str)
{
    int result = 0;
    int neg = 1;
    int i = 0;

    while (str[i] && (str[i] - 48 < 0 || str[i] - 48 > 9))
        i++;
    if (str[i] == 0)
        return (0);
    else {
        neg = is_neg(str[i - 1]);
        for (; str[i] != '\0' && (str[i] - 48 >= 0 && str[i] - 48 <= 9); i++)
            result = result * 10 + str[i] - 48;
        result = result * neg;
        return (result);
    }
}

int my_getnnbr(char const *str, int i)
{
    int result = 0;
    int neg = 1;

    while (str[i] && (str[i] - 48 < 0 || str[i] - 48 > 9))
        i++;
    if (str[i] == 0)
        return (0);
    else {
        neg = is_neg(str[i - 1]);
        for (; str[i] != '\0' && (str[i] - 48 >= 0 && str[i] - 48 <= 9); i++)
            result = result * 10 + str[i] - 48;
        result = result * neg;
        return (result);
    }
}