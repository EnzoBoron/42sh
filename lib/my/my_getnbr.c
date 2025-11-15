/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** get a number from a string
*/

#include "libmy.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    if (str == NULL)
        return 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (nb * neg);
}
