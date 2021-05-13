/*
** EPITECH PROJECT, 2021
** setenv
** File description:
** setenv builtin function
*/

#include "my.h"

int var_exists(s_env **env, char *var)
{
    s_env *tmp = *env;
    for (; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->var, var) == 0)
            return (1);
    }
    return (0);
}

void modify_var(s_env **env, char *var, char *value)
{
    s_env *tmp = *env;
    for (; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->var, var) == 0)
            break;
    }
    tmp->var = my_strdup(var);
    tmp->value = my_strdup(value);
}

void add_env(s_env **env, char *cmd, int status)
{
    char *cmd_var = get_word(cmd, 2);
    char *cmd_value;
    for (int i = 0; cmd_var[i]; i++) {
        if (!(cmd_var[i] >= 'A' && cmd_var[i] <= 'Z') && !(cmd_var[i] >= '0' && cmd_var[i] <= '9')\
        && !(cmd_var[i] >= 'a' && cmd_var[i] <= 'z')) {
            my_printf("%s: Variable name must contain alphanumeric characters.\n", cmd_var);
            return;
        }
    }
    if (status == 0)
        cmd_value = my_strdup("\0");
    if (status == 1)
        cmd_value = get_word(cmd, 3);
    if (var_exists(env, cmd_var))
        modify_var(env, cmd_var, cmd_value);
    else
        create_node(env, cmd_var, cmd_value);
}

int do_setenv(char *cmd, s_env **env)
{
    int arg_nb = count_word(cmd);
    if (arg_nb == 1) {
        do_env(env);
        return (1);
    }
    if (arg_nb == 2) {
        add_env(env, cmd, 0);
        return (1);
    }
    if (arg_nb == 3) {
        add_env(env, cmd, 1);
        return (1);
    }
    if (arg_nb > 3) {
        my_printf("setenv: Too many arguments.\n");
        return (1);
    }
}