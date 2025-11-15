/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_echo
*/

#include "sh42.h"

int have_a_path(char **arr_line)
{
    int i = 1;
    int count = 0;

    for (; arr_line[i] != NULL; i++) {
        for (int j = 0; arr_line[i][j] != '\0'; j++)
            arr_line[i][j] == '$' ? count++ : 0;
    }
    if (count == 0)
        return 1;
    return 0;
}

int my_echo_path(char **env, char **arr_line)
{
    int i = 1;
    int j = 0;
    char *str = NULL;

    env_static(env);
    if (verif_valid_path(env, arr_line) == 1)
        return 0;
    for (; arr_line[i] != NULL; i++) {
        for (j = 0; arr_line[i][j] != '\0'; j++)
            j = my_echo_path_two(arr_line, i, j, str);
        my_printf(" ");
    }
    free(str);
    my_printf("\n");
    return 0;
}

int my_echo(char **env, char **arr_line)
{
    if (have_a_path(arr_line) == 1)
        return 1;
    return my_echo_path(env, arr_line);
}
