/*
** EPITECH PROJECT, 2021
** cd
** File description:
** cd builtin function
*/

#include "my.h"

int do_cd(char *cmd, s_env **env)
{
    int i;
    char *path;
    if (count_word(cmd) > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return (1);
    }
    if (count_word(cmd) == 1)
        path = my_strdup(search_var(env, "HOME"));
    else
        path = get_arg(cmd, path);
    i = chdir(path);
    if (i == -1) {
        my_printf("%s: Not a directory.\n", path);
        return (1);
    }
    modify_var(env, "PWD", getcwd(path, 1024));
    free(path);
    return (1);
}