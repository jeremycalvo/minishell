/*
** EPITECH PROJECT, 2021
** search_cmd
** File description:
** Search Cmd
*/

#include "my.h"

int get_word_len(char *str, int i)
{
    for (; str[i] && str[i] != ' '; i++);
    return (i);
}

char **list_to_tab(s_env **env)
{
    int len = 0;
    s_env *tmp = *env;
    char **tab;
    char *tmp_str;
    for (; tmp; tmp = tmp->next, len++);
    tab = malloc(sizeof(char *) * len + 1);
    tmp = *env;
    for (int i = 0; tmp; tmp = tmp->next, i++) {
        len = my_strlen(tmp->value) + my_strlen(tmp->var) + 2;
        tmp_str = malloc(sizeof(char) * len);
        my_strcpy(tmp_str, tmp->var);
        my_strcat(tmp_str, "=");
        my_strcat(tmp_str, tmp->value);
        tab[i] = my_strdup(tmp_str);
        tab[i + 1] = NULL;
        free(tmp_str);
    }
    return (tab);
}

char **arg_to_tab(char *cmd)
{
    char **tab = malloc(sizeof(char *) * (count_word(cmd)) + 1);
    for (int i = 0, r = 0; cmd[i] && cmd[i] != '\n'; r++, i++) {
        tab[r] = malloc(sizeof(char) * (get_word_len(cmd, i) + 2));
        for (int p = 0; cmd[i] && cmd[i] != ' ' && cmd[i] != '\n'; i++, p++) {
            tab[r][p] = cmd[i];
            tab[r][p + 1] = '\0';
        }
        while (cmd[i + 1] == ' ')
            i++;
        tab[r + 1] = NULL;
    }
    return (tab);
}