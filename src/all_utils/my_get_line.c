/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_get_line
*/

#include "sh42.h"

char **static_env(char **envp)
{
    static char **env = 0;

    if (envp != NULL)
        env = envp;
    return env;
}

void handler(int signal __attribute__((unused)))
{
    write(1, "\n", 1);
    return_value(1);
    isatty(0) ? my_prompt(static_env(NULL)) : 0;
}

char *my_get_line_two(char *line, int len)
{
    if (len == 1) {
        return_value(0);
        free(line);
        return NULL;
    }
    line[len] = '\0';
    char *clean = my_clean_str(line);
    free(line);
    return clean;
}

char *my_get_line(char **arr_path, char **env)
{
    char *line = NULL;
    size_t size = 0;
    int len = 0;

    static_env(env);
    signal(SIGINT, handler);
    len = getline(&line, &size, stdin);
    if (len == -1 || my_strcmp(line, "exit\n") == 0) {
        isatty(0) ? my_printf("exit\n") : 0;
        env[0] != NULL ? my_free_array(arr_path) : 0;
        free(line);
        exit(return_value(-1));
    }
    return my_get_line_two(line, len);
}
