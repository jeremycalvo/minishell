/*
** EPITECH PROJECT, 2021
** cmd
** File description:
** Commands interpretation
*/

#include "my.h"

int unknown_cmd(char *word)
{
    my_printf("%s: Command not found.\n", word);
    return (1);
}

int interpret_cmd(char *cmd, s_env **env)
{
    char *word = get_word(cmd, 1);
    int n = 0;
    (my_strcmp(word, "pwd") == 0) && (do_pwd(cmd)) && (n++);
    (my_strcmp(word, "exit") == 0) && (do_exit()) && (n++);
    (my_strcmp(word, "env") == 0) && (do_env(env)) && (n++);
    (my_strcmp(word, "cd") == 0) && (do_cd(cmd, env)) && (n++);
    (my_strcmp(word, "setenv") == 0) && (do_setenv(cmd, env)) && (n++);
    (my_strcmp(word, "unsetenv") == 0) && (do_unsetenv(cmd, env)) && (n++);
    (my_strcmp(word, "\0") == 0) && (n++);
    (n == 0) && (n = search_cmd(cmd, env, word));
    (n == 0) && (unknown_cmd(word));
    free(word);
}