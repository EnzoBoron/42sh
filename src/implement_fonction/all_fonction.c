/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** fonction
*/

#include "sh42.h"

int allias(char **env, char **arr_line, char **arr_path)
{
    if (my_strcmp(arr_line[0], "c") == 0) {
        char *arr[] = {"clear", NULL};
        my_execve(arr, arr_path, env);
        return 0;
    }
    return 1;
}

int fonction(char **env, char **arr_line, char **arr_path)
{
    if (env[0] == NULL)
        return 0;
    if (my_strcmp(arr_line[0], "cd") == 0)
        return my_cd(env, arr_line);
    if (my_strcmp(arr_line[0], "setenv") == 0)
        return my_setenv(env, arr_line);
    if (my_strcmp(arr_line[0], "unsetenv") == 0)
        return my_unsetenv(env, arr_line);
    if (my_strcmp(arr_line[0], "echo") == 0)
        return my_echo(env, arr_line);
    return allias(env, arr_line, arr_path);
}
