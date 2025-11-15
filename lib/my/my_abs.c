/*
** EPITECH PROJECT, 2023
** my_abs
** File description:
** absolute value
*/

#include "libmy.h"

int my_abs(int nb)
{
    if (nb < 0)
        nb = nb * -1;
    return (nb);
}
