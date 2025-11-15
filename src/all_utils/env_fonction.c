/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** env_fonction
*/

#include "sh42.h"

char *my_search_in_env(char **env, char *search)
{
    int len = my_strlen(search);
    char *path = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], search, len) == 0) {
            path = my_strndup(env[i], len);
            return path;
        }
    }
    return NULL;
}

int were_is_the_path(char **env, char *search)
{
    int i = 0;
    for (; env[i] != NULL; i++) {
        if (my_strncmp(env[i], search, my_strlen(search)) == 0 && (env[i]
        [my_strlen(search)] == '=' || env[i][my_strlen(search) - 1] == '='))
            return (i);
    }
    return i;
}
