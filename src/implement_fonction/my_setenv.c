/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_setenv
*/

#include "sh42.h"

int have_alphanum(char **arr_line)
{
    if ((arr_line[1][0] < 'A' || arr_line[1][0] > 'Z') && (arr_line[1][0] < 'a'
    || arr_line[1][0] > 'z')) {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return_value(1);
        return 1;
    }
    if (my_str_is_alpha(arr_line[1]) == 1) {
        my_putstr_error("setenv: Variable name must");
        my_putstr_error(" contain alphanumeric characters.\n");
        return_value(1);
        return 1;
    }
    return 0;
}

int my_setenv_two(char **env, char **arr_line, int env_len)
{
    if (have_alphanum(arr_line) == 1)
        return 0;
    if (were_is_the_path(env, arr_line[1]) == env_len)
        return the_arg_anvailable(env, arr_line);
    else
        return the_arg_available(env, arr_line);
    return 0;
}

int my_setenv(char **env, char **arr_line)
{
    int env_len = 0;

    if (arr_line[1] == NULL) {
        my_print_array(env);
        my_free_array(arr_line);
        return 0;
    }
    if (my_array_len(arr_line) > 3) {
        my_free_array(arr_line);
        return_value(1);
        write(2, "setenv: Trop d'arguments.\n", 27);
        return 0;
    }
    for (; env[env_len] != NULL; env_len++);
    return my_setenv_two(env, arr_line, env_len);
}
