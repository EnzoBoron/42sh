/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_unsetenv
*/

#include "sh42.h"

int my_unsetenv(char **env, char **arr_line)
{
    int were_is_the = 0;

    if (arr_line[1] == NULL) {
        my_printf("unsetenv: Trop peu d'arguments\n");
        my_free_array(arr_line);
        return 0;
    } else {
        if (my_search_in_env(env, arr_line[1]) == NULL) {
            my_free_array(arr_line);
            return 0;
        }
        were_is_the = were_is_the_path(env, arr_line[1]);
        for (;env[were_is_the + 1] != NULL; were_is_the++)
            env[were_is_the] = env[were_is_the + 1];
        env[were_is_the] = NULL;
    }
    my_free_array(arr_line);
    return 0;
}
