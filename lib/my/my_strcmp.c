/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** lib
*/

int  my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        i++;
        if (s1[i] == '\0' && s2[i] == '\0')
            break;
    }
    if (s1[i] > s2[i]) {
        return (s1[i]);
    }
    if (s2[i] > s1[i])
        return (s2[i] * -1);
    if (s1[i] == s2[i])
        return (0);
}
