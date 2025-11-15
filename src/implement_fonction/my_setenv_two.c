/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_setenv_two
*/

#include "sh42.h"

int the_arg_available(char **env, char **arr_line)
{
    int i = 0;
    int were_is_the = 0;

    were_is_the = were_is_the_path(env, arr_line[1]);
    for (; env[were_is_the][i] != '='; i++) {
        env[were_is_the][i] = arr_line[1][i];
    }
    env[were_is_the][i] = '=';
    i++;
    env[were_is_the][i] = '\0';
    return 0;
}

int set_seconde_part(char **env, char **arr_line, int i, int j)
{
    if (arr_line[2] != NULL)
        for (int se = 0; arr_line[2][se] != '\0'; se++, j++)
            env[i][j + 1] = arr_line[2][se];
    return j;
}

int the_arg_anvailable(char **env, char **arr_line)
{
    int i = 0;
    int j = my_strlen(arr_line[1]);

    for (i = 0; env[i] != NULL; i++);
    env[i] = arr_line[1];
    env[i][j] = '=';
    j = set_seconde_part(env, arr_line, i, j);
    env[i][j + 1] = '\0';
    env[i + 1] = NULL;
    return 0;
}
