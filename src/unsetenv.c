/*
** EPITECH PROJECT, 2021
** unsetenv
** File description:
** Unsetenv builtin
*/

#include "my.h"

int do_unsetenv(char *cmd, s_env **env)
{
    int arg_nb = count_word(cmd);
    s_env *tmp = *env;
    s_env *tmp2 = *env;
    char *var;
    if (arg_nb == 1) {
        my_printf("unsetenv: Too few arguments.\n");
        return (1);
    }
    var = get_word(cmd, 2);
    for (; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->var, var) == 0)
            break;
    }
    if (tmp != NULL) {
        for (; tmp2->next != tmp; tmp2 = tmp2->next);
        tmp2->next = tmp->next;
        free (tmp);
    }
    return (1);
}