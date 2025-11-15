/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reverse a string
*/

#include "libmy.h"

char *my_revstr(char *str)
{
    char c;
    int i = 0;
    int j;

    if (str == NULL)
        return (NULL);
    j = my_strlen(str) - 1;
    while (i < j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}
