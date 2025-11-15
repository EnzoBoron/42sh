/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_cd_two
*/

#include "sh42.h"

int nbr_pass(int nouveauNombre)
{
    static int nombre = 0;
    if (nouveauNombre != 0) {
        nombre = nouveauNombre;
    }
    return nombre;
}

int my_setenv_cd(char **env, char *value, char *env_path)
{
    char path[4096];
    struct stat sb;
    if (chdir(value) != 0) {
        if (stat(value, &sb) == 0 && S_ISREG(sb.st_mode) == 1)
            return 2;
        return 1;
    }
    if (getcwd(path, sizeof(path)) == NULL) {
        return 1;
    }
    int i = 0;
    int o = 0;
    int were_is_the = were_is_the_path(env, env_path);
    for (; env_path[i] != '\0'; i++);
    for (; path[o] != '\0'; i++, o++) {
        env[were_is_the][i] = path[o];
    }
    env[were_is_the][i] = '\0';
    return 0;
}

void cd_setenv_alter(char **env, char *str, char *str2)
{
    int i = 0;
    int o = 0;
    int were_is_the = were_is_the_path(env, str);
    for (; str[i] != '\0'; i++);
    for (; str2[o] != '\0'; i++, o++) {
        env[were_is_the][i] = str2[o];
    }
    env[were_is_the][i] = '\0';
}
