/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** swap two int
*/

#include "libmy.h"

int my_swap(int *a, int *b)
{
    int swap;

    if (a == NULL || b == NULL)
        return (84);
    swap = *a;
    *a = *b;
    *b = swap;
    return (0);
}
