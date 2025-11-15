/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execve
*/

#include "sh42.h"

int exec_ve(char **arr_line, char **arr_path, char **env, char *outfile)
{
    struct stat st;
    char *res;
    for (int i = 0; arr_path[i] != NULL; i++) {
        res = my_strcat(arr_path[i], "/");
        res = my_strcat(res, arr_line[0]);
        simple_redirection(arr_line, res, env, outfile);
    }

    if (stat(arr_line[0], &st) == 0) {
        if (access(arr_line[0], R_OK) != 0 || access(arr_line[0], X_OK) != 0)
            my_printf("%s: Permission denied.\n", arr_line[0]);
    } else {
        if (access(arr_line[1], X_OK) == -1) {
            my_putstr_error(arr_line[0]);
            my_putstr_error(": Command not found.\n");
        }
    }
    exit (1);
}

char *redirect(char **arr_line, int *i)
{
    char *out = NULL;
    if (my_strcmp(arr_line[*i], ">>\0") == 0 && arr_line[*i + 1] != NULL) {
        out = arr_line[*i + 1];
        arr_line[*i] = NULL;
        i_static(1);
        return out;
    }
    if (my_strcmp(arr_line[*i], ">\0") == 0 && arr_line[*i + 1] != NULL) {
        out = arr_line[*i + 1];
        arr_line[*i] = NULL;
        i_static(0);
        return out;
    }
    return NULL;
}

void exec(char **arr_line, char **arr_path, char **env, pid_t pid)
{
    char *outfile = NULL;
    int status = 0;

    for (int i = 0; arr_line[i] != NULL; i++) {
        outfile = redirect(arr_line, &i);
        if (outfile != NULL)
            break;
        if (my_strcmp(arr_line[i], "|") == 0 && arr_line[i + 1] != NULL)
            return pipe_execve(arr_line, arr_path, env, i);
    }
    exec_ve(arr_line, arr_path, env, outfile);
    waitpid(pid, &status, 0);
    return_value(WEXITSTATUS(status));
}

void my_execve(char **arr_line, char **arr_path, char **env)
{
    pid_t pid = fork();

    if (pid == 0)
        exec(arr_line, arr_path, env, pid);
    else
        segfault(pid);
}
