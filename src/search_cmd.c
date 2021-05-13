/*
** EPITECH PROJECT, 2021
** search_cmd
** File description:
** search_cmd
*/

#include "my.h"

char *search_var(s_env **env, char *var)
{
    s_env *tmp = *env;
    for (; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(var, tmp->var) == 0)
            return (tmp->value);
    }
    return (NULL);
}

char *check_access(char *check_path, char *token, char *cmd)
{
    int len = my_strlen(token) + my_strlen(cmd) + 3;
    check_path = malloc(sizeof(char) * len);
    my_strcpy(check_path, token);
    my_strcat(check_path, "/");
    my_strcat(check_path, cmd);
    if (check_path[my_strlen(check_path) - 1] == '\n')
        check_path[my_strlen(check_path) - 1] = '\0';
    if (access(check_path, F_OK) == 0)
        return (check_path);
    return (NULL);
}

void my_exec(char *cmd, s_env **env, char *path)
{
    char **args = arg_to_tab(cmd);
    char **char_env = list_to_tab(env);
    pid_t test = fork();
    int *status;
    int wait_return;
    if (test == -1)
        return;
    else if (test == 0) {
        execve(path, args, char_env);
    } else {
        do {
            wait_return = wait(status);
        } while (wait_return != -1 && wait_return != test);
    }
    free(args);
    free(char_env);
}

int search_cmd(char *cmd, s_env **env, char *word)
{
    char *paths = my_strdup(search_var(env, "PATH"));
    char *token = strtok(paths, ":");
    char *check_path;
    while (token != NULL) {
        check_path = check_access(check_path, token, word);
        if (check_path != NULL) {
            break;
        }
        token = strtok(NULL, ":");
    }
    if (token != NULL) {
        my_exec(cmd, env, check_path);
        return (1);
    }
    return (0);
}