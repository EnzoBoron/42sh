/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** return_value
*/

#include "sh42.h"

int return_value(int nb)
{
    static int return_value = 0;

    if (nb != -1)
        return_value = nb;
    return return_value;
}
