/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_echo_two
*/

#include "sh42.h"

int verif_valid_path_two(char **env, char **arr, char *str, int o)
{
    for (o = 1; arr[o] != NULL; o++) {
        if (arr[o][0] == '?')
            return 0;
        str = transfer_in_maj(arr[o]);
        if (my_search_in_env(env, str) == NULL) {
            my_printf("%s: Undefined variable.\n", arr[o]);
            return 1;
        }
    }
    return 0;
}

int verif_valid_path(char **env, char **arr_line)
{
    int i;
    int o = 1;
    char *str = malloc(sizeof(char) * 100);
    char **arr = NULL;

    for (i = 1; arr_line[i] != NULL; i++) {
        arr = my_str_to_word_array(arr_line[i], '$');
        if (verif_valid_path_two(env, arr, str, o) == 1)
            return 1;
    }
    my_free_array(arr);
    free(str);
    return 0;
}

char **env_static(char **envp)
{
    static char **env = NULL;

    if (env == NULL)
        env = envp;
    return env;
}

int my_echo_path_two(char **arr_line, int i, int j, char *str)
{
    if (arr_line[i][j] == '$') {
        if (arr_line[i][j + 1] == '?') {
            my_printf("%d ", return_value(-1));
            return j + my_strlen(arr_line[i]) - 1;
        }
        arr_line[i] = transfer_in_maj(arr_line[i] + j + 1);
        str = my_search_in_env(env_static(NULL), arr_line[i]);
        if (str == NULL)
            return j;
        my_printf("%s ", str + 1);
        j += my_strlen(str) - 1;
    } else
        my_printf("%c", arr_line[i][j]);
    return j;
}
