/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** pipes
*/

#include "sh42.h"

void pipe_execve(char **arr_line, char **arr_path, char **env, int i)
{
    int fd[2];
    int status = 0;
    pid_t pid;

    pipe(fd);
    pid = fork();
    if (pid == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        arr_line[i] = NULL;
        exec_ve(arr_line, arr_path, env, NULL);
    } else {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        exec_ve(&arr_line[i + 1], arr_path, env, NULL);
    }
    waitpid(pid, &status, 0);
    return_value(WEXITSTATUS(status));
}
