/*
** EPITECH PROJECT, 2022
** my_putnbr
** File description:
** put a number
*/

#include "libmy.h"

void my_putnbr(int nb)
{
    char c = 0;

    if (nb < 0) {
        write(1, "-", 1);
        nb = my_abs(nb);
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else {
        c = nb + '0';
        write(1, &c, 1);
    }
}
