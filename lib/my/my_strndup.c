/*
** EPITECH PROJECT, 2023
** my_strndup
** File description:
** copy n char of a string
*/

#include "libmy.h"

char *my_strndup(char const *src, int n)
{
    int i = n;
    int o = 0;
    char *dest;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        return (NULL);
    for (; src[i] != '\0'; i++) {
        dest[o] = src[i];
        o++;
    }
    dest[o] = '\0';
    return (dest);
}
