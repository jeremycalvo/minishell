/*
** EPITECH PROJECT, 2021
** list
** File description:
** create linked list
*/

#include "my.h"

void create_node(s_env **list, char *var, char *value)
{
    s_env *element = malloc(sizeof(*element));
    s_env *tmp = *list;
    element->var = my_strdup(var);
    element->value = my_strdup(value);
    element->next = NULL;
    if (*list == NULL) {
        *list = element;
        return;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = element;
}

s_env *create_list(char **env)
{
    s_env *list = NULL;
    for (int i = 0; env[i]; i++) {
        create_node(&list, get_env_var(env[i]), get_env_value(env[i]));
    }
    return (list);
}