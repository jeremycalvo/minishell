/*
** EPITECH PROJECT, 2021
** pwd
** File description:
** pwd buitlin function
*/

#include "my.h"

int do_pwd(char *cmd)
{
    size_t len = 1024;
    char *cwd = malloc(sizeof(char) * 1025);
    getcwd(cwd, len);
    my_printf("%s\n", cwd);
    free(cwd);
    return (1);
}