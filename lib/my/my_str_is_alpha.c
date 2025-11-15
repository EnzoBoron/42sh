/*
** EPITECH PROJECT, 2023
** my_str_is_alpha
** File description:
** check if the string is alphabetical
*/

#include "libmy.h"

int my_str_is_alpha(char *str)
{
    int i = 0;

    if (str == NULL)
        return 1;
    for (; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
            return 1;
    }
    return 0;
}
