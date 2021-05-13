/*
** EPITECH PROJECT, 2020
** is_char_in_str
** File description:
** Is char in str
*/

int is_char_in_str(char c, char *str)
{
    for (int i = 0; str[i]; i++) {
        if (c == str[i])
            return (1);
    }
    return (0);
}