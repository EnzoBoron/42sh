/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main of 42sh
*/

#include "sh42.h"

int main(int ac , char **av __attribute__((unused)), char **env)
{
    char **my_env = (ac == 1) ? env : NULL;

    if (ac != 1)
        return 84;
    shell(my_env);
    my_free_array(my_env);
    return 0;
}
