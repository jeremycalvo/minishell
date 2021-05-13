/*
** EPITECH PROJECT, 2021
** env
** File description:
** env builtin function
*/

#include "my.h"

int do_env(s_env **env)
{
    for (s_env *tmp = *env; tmp; tmp = tmp->next)
        my_printf("%s%c%s\n", tmp->var, 61, tmp->value);
    return (1);
}