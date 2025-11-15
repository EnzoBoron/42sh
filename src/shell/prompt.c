/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prompt
*/

#include "sh42.h"

int first_part_prompt(char **env)
{
    char *name;

    if (env[0] == NULL) {
        my_printf("> ");
        return 1;
    }
    if (return_value(-1) == 0)
        my_printf("%s$ ", green);
    else
        my_printf("%s$[%d] ", red, return_value(-1));
    name = my_search_in_env(env, "USER=");
    if (name != NULL)
        my_printf("%s%s%s", blue, name, normal);
    free(name);
    return 0;
}

void my_prompt(char **env)
{
    char *pwd;
    int len = 0;
    int o = 0;
    int i = 0;

    if (first_part_prompt(env) == 1 || !(pwd = my_search_in_env(env, "PWD=")))
        return;
    len = my_strlen(pwd);
    for (i = 0; pwd[i] != '\0'; i++)
        pwd[i] == '/' ? o++ : 0;
    if (o == 2)
        my_printf(":~");
    else {
        i = len;
        for (; pwd[i] != '/'; i--);
        my_printf("%s:%s %s", cyan, &pwd[i], normal);
    }
    my_printf("%s> %s", white, normal);
}
