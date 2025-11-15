/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** segfault
*/

#include "sh42.h"

int segfault(pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);
    return_value(WEXITSTATUS(status));
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV) {
        if (WCOREDUMP(status)) {
            write(STDERR_FILENO, "Segmentation fault (core dumped)\n", 34);
            return_value((128 + SIGSEGV));
            return 0;
        } else {
            write(STDERR_FILENO, "Segmentation fault\n", 19);
            return_value((128 + SIGSEGV));
            return 0;
        }
    }
    return 0;
}
