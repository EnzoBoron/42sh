/*
** EPITECH PROJECT, 2023
** my_str_is_number
** File description:
** check if the string is a number
*/

#include "libmy.h"

int my_str_is_numb(char *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return 1;
    }
    return 0;
}
