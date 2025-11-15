/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell of 42sh
*/

#include "sh42.h"

void execute_commands(char **env, char **arr_path, char **arr_line,
int and_status)
{
    char **arr_command;

    for (int i = 0; arr_line[i] != NULL; i++) {
        if (!(arr_command = my_str_to_word_array(arr_line[i], ' ')) ||
        fonction(env, arr_command, arr_path) == 0)
            continue;
        my_execve(arr_command, arr_path, env);
        if (return_value(-1) != 0 && and_status == 1)
            break;
        my_free_array(arr_command);
    }
}

void boucle_shell(char **env, char **arr_path)
{
    char *line;
    int and_status = 0;
    char **arr_line;

    isatty(0) ? my_prompt(env) : 0;
    line = my_get_line(arr_path, env);
    if (line == NULL)
        return;
    and_status = have_and(line, and_status);
    arr_line = my_str_to_word_array(line, ';');
    clean_arr(arr_line);
    execute_commands(env, arr_path, arr_line, and_status);
    my_free(2, arr_line, STRING_ARRAY, line, STRING);
}

void shell(char **env)
{
    char *path;
    char **arr_path;

    path = my_search_in_env(env, "PATH=");
    arr_path = my_str_to_word_array(path, ':');
    free(path);
    while (1)
        boucle_shell(env, arr_path);
    my_free_array(arr_path);
}
