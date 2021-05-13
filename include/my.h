/*
** EPITECH PROJECT, 2020
** my
** File description:
** Prototypes lib
*/

#ifndef MY_H
#define MY_H

// Minishell includes
#include <stdarg.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

// Lib prototypes
int my_atoi(char const *str);
int is_neg(char a);
int my_getnbr(char const *str);
int reste(int nb, int i);
int my_is_prime(int nb);
int my_isneg(int nb);
char *my_itoa(int nb);
int my_put_nbr(int nb);
int my_putchar(char c);
int my_putstr(char const *str);
void my_swaprev(char *a, char *b);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int  my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int p);
void my_swap(int *a, int *b);
int my_printf(char *str, ...);
int my_put_octal(unsigned long int nb);
int my_put_hex(unsigned long int nb);
int my_put_hex_low(unsigned long int nb);
int my_cleanstr(char *str);
char *char_to_octal(int nb);
int my_put_binary(unsigned long int nb);
int is_char_in_str(char c, char *str);
int my_put_unsigned_nbr(unsigned int nb);
int my_getnnbr(char const *str, int i);
int my_intlen(int nb);
int my_formated_print(char c, int nb);
int my_format(char *str, int i, va_list parameters);
int my_format_plus(char *str, int i, va_list parameters);
int my_put_pointer(unsigned long int nb);
char *my_strdup(char const *src);

// Minishell defines
typedef struct s_env {
    char *var;
    char *value;
    struct s_env *next;
} s_env;

// Minishell prototypes
int interpret_cmd(char *cmd, s_env **env);
char *get_word(char *str, int nb);
int do_pwd(char *cmd);
int do_exit(void);
int count_word(char *str);
int do_env(s_env **env);
int do_cd(char *cmd, s_env **env);
char *get_arg(char *str, char *arg);
int do_setenv(char *cmd, s_env **env);
char *get_env_var(char *cmd);
char **copy_arr(char **cpy, char **arr);
void add_env_var(char **env, char *var, char *value);
void replace_env_var(char **env, int i, char *var, char *value);
s_env *create_list(char **env);
char *get_env_value(char *cmd);
void create_node(s_env **list, char *var, char *value);
int do_unsetenv(char *cmd, s_env **env);
int search_cmd(char *cmd, s_env **env, char *word);
char **arg_to_tab(char *cmd);
char **list_to_tab(s_env **env);
void modify_var(s_env **env, char *var, char *value);
char *search_var(s_env **env, char *var);
#endif
