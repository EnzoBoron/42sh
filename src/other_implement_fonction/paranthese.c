/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-42sh-enzo.boron
** File description:
** parenthèse.c
*/

#include "sh42.h"

void is_parentese_commande_line(char **path)
{
     for (int i = 0; path[i]; i++) {
        if (path[i][0] == '(' && path[i + 1] != NULL) {
            path[i][0] = ' ';
        }
    }

    return;
}

void open_parenthese(char **path)
{
    for (int i = 0; path[i]; i++) {
        if (path[i][0] == '(') {
            is_parentese_commande_line(path);
            //is_instruction_serie(path);
        }
    }
}