/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** concatenate two strings into a the first one
*/

#include "libmy.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);

    dest = my_realloc(dest, len + my_strlen(src) + 1);
    if (dest == NULL || src == NULL)
        return NULL;
    for (int i = 0; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    dest[len + my_strlen(src)] = '\0';
    return dest;
}
