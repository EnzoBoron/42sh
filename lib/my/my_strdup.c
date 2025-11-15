/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** duplicate a string
*/

#include "libmy.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        return (NULL);
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
