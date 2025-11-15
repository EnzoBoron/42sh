/*
** EPITECH PROJECT, 2023
** my_realloc
** File description:
** realloc a string
*/

#include "libmy.h"

void *my_realloc(char *str, int size)
{
    int i = 0;
    char *new = malloc(sizeof(char) * (size + 1));

    if (new == NULL)
        return (NULL);
    while (str[i] != '\0') {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    str = malloc(sizeof(char) * (size + 1));
    if (str == NULL)
        return (NULL);
    for (int j = 0; new[j] != '\0'; j++)
        str[j] = new[j];
    str[i] = '\0';
    free(new);
    return (str);
}
