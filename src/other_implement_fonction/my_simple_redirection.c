/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** simple_redirection
*/

#include "sh42.h"

int i_static(int nb)
{
    static int i = 0;

    if (nb == -1)
        return i;
    i = nb;
    return 0;
}

void simple_redirection(char **arr_line, char *res, char **env, char *outfile)
{
    int fd = 0;

    if (outfile != NULL) {
        if (i_static(-1) == 0)
            fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (i_static(-1) == 1)
            fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd == -1) {
            perror("open");
            exit(1);
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }
    if (execve(res, arr_line, env) != -1 ||
    execve(arr_line[0], arr_line, env) != -1)
        exit(0);
    free(res);
}

void anti_redirection(char **arr_line, char *res, char **env, char *outfile)
{
    int fd = 0;

    if (outfile != NULL) {
        my_printf("<\n");
        if (i_static(-1) == 2)
            fd = open(outfile, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(1);
        }

        close(fd);
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }
    if (execve(res, arr_line, env) != -1 ||
    execve(arr_line[0], arr_line, env) != -1)
        exit(0);
    free(res);
}
