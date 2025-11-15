/*
** EPITECH PROJECT, 2023
** my_array_len
** File description:
** return the length of an array
*/

#include "libmy.h"

int my_array_len(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return (0);
    for (; arr[i] != NULL; i++);
    return (i);
}
