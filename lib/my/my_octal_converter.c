/*
** EPITECH PROJECT, 2022
** my_octal_converter
** File description:
** convert a number into octal
*/

#include "libmy.h"

int my_octal_converter(int nb)
{
    int octal = 0;
    int i = 1;

    if (nb == 0)
        return (0);
    while (nb != 0) {
        octal += (nb % 8) * i;
        nb /= 8;
        i *= 10;
    }
    return (octal);
}
