/*
** EPITECH PROJECT, 2021
** getenv2
** File description:
** setenv builtin fucntion
*/

#include "my.h"

char *get_env_value(char *cmd)
{
    char *value;
    int i = 0;
    int p = 0;
    for (; cmd[i] != 61; i++);
    i++;
    for (p = i; cmd[p]; p++);
    value = malloc(sizeof(char) * (p + 1));
    p = 0;
    for (; cmd[i]; i++, p++)
        value[p] = cmd[i];
    value[p] = '\0';
    return (value);
}

char *get_env_var(char *cmd)
{
    char *var;
    int i = 0;
    int p = 0;
    for (; cmd[p] != 61; p++);
    var = malloc(sizeof(char) * p + 1);
    for (; cmd[i] != 61; i++)
        var[i] = cmd[i];
    var[i] = '\0';
    return (var);
}