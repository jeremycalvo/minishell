/*
** EPITECH PROJECT, 2021
** get_word
** File description:
** get_word
*/

#include "my.h"

int count_word(char *str)
{
    int nb = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            nb++;
        }
    }
    return (nb + 1);
}

char *get_word(char *str, int nb)
{
    int r = 1;
    int i = 0;
    int len = 0;
    char *word;
    for (; r < nb; r++) {
        for (; str[i] && str[i] != ' '; i++);
        for (; str[i] && str[i] == ' '; i++);
    }
    for (int n = i; str[n] && str[n] != ' '; n++, len++);
    word = malloc(sizeof(char) * (len + 1));
    r = 0;
    for (; str[i] && str[i] != ' ' && str[i] != '\n'; i++, r++)
        word[r] = str[i];
    word[r] = '\0';
    return (word);
}

char *get_arg(char *str, char *arg)
{
    int i = 0;
    int p = 0;
    arg = malloc(sizeof(str));
    for (; str[i - 1] != ' '; i++);
    for (; str[i]; i++, p++)
        arg[p] = str[i];
    arg[p] = '\0';
    if (arg[p - 1] == '\n')
        arg[p - 1] = '\0';
    return (arg);
}