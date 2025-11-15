/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** display N if the number is negative, P otherwise
*/

#include "libmy.h"

void my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
}
