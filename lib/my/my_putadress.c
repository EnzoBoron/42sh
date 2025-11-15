/*
** EPITECH PROJECT, 2022
** my_putadress
** File description:
** display an adress of a pointer
*/

#include "libmy.h"

void my_putadress(void *adress)
{
    if (adress == NULL) {
        my_putstr("(nil)");
        return;
    }
    my_putstr("0x");
    my_putnbr_base((long)adress, "0123456789abcdef");
}
