/*
** EPITECH PROJECT, 2022
** my_putfoat
** File description:
** print a float
*/

#include "libmy.h"

void my_putfloat(double n, int prec)
{
    int part_int = 0;
    int part_dec = 0;
    int i = 0;

    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    part_int = n;
    my_putnbr(part_int);
    my_putchar('.');
    n = n - part_int + 0.5 / my_pow(10, prec);
    while (i < prec) {
        n = n * 10;
        part_dec = n;
        my_putnbr(part_dec);
        n = n - part_dec;
        i++;
    }
}
