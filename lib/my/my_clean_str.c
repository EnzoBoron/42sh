/*
** EPITECH PROJECT, 2023
** my_clean_str
** File description:
** fonction who clean a string
*/

#include "libmy.h"

void while_boucle(int *j, char *clean)
{
    while (*j % 8 != 0)
        clean[(*j)++] = ' ';
}

void boucle_string (char *str, char *clean, int *i, int *j)
{
    if (str[*i] == ' ' || str[*i] == '\t') {
        for (;str[*i + 1] == ' ' || str[*i + 1] == '\t' ||
        str[*i + 1] == '<'; (*i)++);
        clean[(*j)++] = ' ';
    } else {
        if (str[*i] == '\t') {
            while_boucle(j, clean);
        } else {
            clean[(*j)++] = str[*i];
        }
    }
    if (str[*i] == ';' &&
    str[*i + 1] == ';') {
        for (;str[*i] == ';'; (*i)++);
    }
}

char *my_clean_str(char *str)
{
    int i = 0;
    int j = 0;
    char *clean;

    if (str == NULL)
        return NULL;
    clean = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (clean == NULL)
        return NULL;
    for (i = 0; str[i] == ' ' || str[i] == '\t'; i++);
    for (j = 0; str[i] != '\0'; i++) {
        boucle_string(str, clean, &i, &j);
    }
    for (; j > 0 &&
    (clean[j - 1] == ' ' || clean[j - 1] == '\t' || clean[j - 1] == '\n');
    j--);
    clean[j] = '\0';
    return clean;
}
