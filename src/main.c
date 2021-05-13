/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"

void sighandler(int signum)
{
    write(2, "Segmentation fault\n", 19);
    exit(84);
}

char **copy_arr(char **cpy, char **arr)
{
    int i = 0;
    cpy = malloc(sizeof(arr) + 1);
    for (; arr[i]; i++) {
        cpy[i] = my_strdup(arr[i]);
    }
    cpy[i] = NULL;
    return (cpy);
}

int main(int ac, char **av, char **env)
{
    char *cmd;
    size_t len = 1024;
    s_env *list = create_list(env);
    if (ac != 1)
        exit(84);
    signal(SIGSEGV, sighandler);
    while (1) {
        cmd = malloc(sizeof(cmd) * 1025);
        cmd[0] = '\0';
        write(0, "$> ", 3);
        if (getline(&cmd, &len, stdin) == -1) {
            exit(0);
        }
        interpret_cmd(cmd, &list);
        free(cmd);
    }
    return (0);
}