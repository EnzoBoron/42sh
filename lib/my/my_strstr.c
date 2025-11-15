/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** find a string in a string
*/

#include "libmy.h"

char *my_strstr(char *str, char *to_find)
{
    if (str == NULL || to_find == NULL)
        return (0);
    while (*str != '\0') {
        if ((*str == *to_find) && my_strcmp(str, to_find)) {
            return (str);
        }
        str++;
    }
    return (0);
}
