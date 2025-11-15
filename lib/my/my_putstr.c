/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** put a string
*/

#include "libmy.h"

void my_putstr(char const *str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
}
