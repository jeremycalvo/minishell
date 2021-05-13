/*
** EPITECH PROJECT, 2020
** my
** File description:
** Prototypes lib
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>

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
#endif
