/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_cd
*/

#include "sh42.h"

int cd_drawn(char **env, char **arr_line)
{
    if (were_is_the_path(env, "OLDPWD=") == my_array_len(env))
        return 0;
    if (arr_line[1][1] != '\0') {
        my_printf("Usage: cd [-plvn][-|<dir>].\n");
        my_free_array(arr_line);
        return (0);
    }
    char *old_pwd = my_search_in_env(env, "OLDPWD=");
    char *pwd = my_search_in_env(env, "PWD=");
    if (my_strcmp(old_pwd, pwd) == 0 && nbr_pass(0) == 0)
        my_printf(": No such file or directory.\n");
    else {
        cd_setenv_alter(env, "OLDPWD=", pwd);
        cd_setenv_alter(env, "PWD=", old_pwd);
        chdir(old_pwd);
        nbr_pass(1);
    }
    my_free(2, old_pwd, STRING, pwd, STRING);
    return 0;
}

int my_cd_following(char **env, char **arr_line)
{
    int i = 0;

    if (arr_line[2] != NULL) {
        my_printf("cd: Too many arguments.\n");
        my_free_array(arr_line);
        return (0);
    }
    if (arr_line[1] != NULL) {
        if (arr_line[1][0] == '-' && arr_line[1][1] == '\0')
            return (cd_drawn(env, arr_line));
        if (were_is_the_path(env, "OLDPWD=") != my_array_len(env))
            cd_setenv_alter(env, "OLDPWD=", my_search_in_env(env, "PWD="));
        i = my_setenv_cd(env, arr_line[1], "PWD=");
        i == 1 ? my_printf("%s: No such file or directory.\n",
        arr_line[1]) : 0;
        i == 2 ? my_printf("%s: Not a directory.\n", arr_line[1]) : 0;
        my_free_array(arr_line);
        return (0);
    }
    return (0);
}

int my_cd(char **env, char **arr_line)
{
    if (arr_line[1] == NULL) {
        if (my_search_in_env(env, "HOME=") == NULL) {
            my_printf("cd: No home directory.\n");
            return (0);
        }
        char *home = my_search_in_env(env, "HOME=");
        struct stat sb;
        if (stat(home, &sb) == -1) {
            my_printf("cd: Cannot access home directory.\n");
            my_free(2, home, STRING, arr_line, STRING_ARRAY);
            return (0);
        }
        if (were_is_the_path(env, "OLDPWD=") != my_array_len(env))
            cd_setenv_alter(env, "OLDPWD=", my_search_in_env(env, "PWD="));
        my_setenv_cd(env, home, "PWD=");
        my_free(2, home, STRING, arr_line, STRING_ARRAY);
        return (0);
    }
    return my_cd_following(env, arr_line);
}
