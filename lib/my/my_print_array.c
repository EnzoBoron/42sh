/*
** EPITECH PROJECT, 2022
** my_print_array
** File description:
** print an array
*/

#include "libmy.h"

void my_print_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        write(1, "\n", 1);
    }
}
