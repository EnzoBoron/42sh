/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-enzo.boron
** File description:
** 42sh
*/

#include "libmy.h"
#include <signal.h>
#include <sys/wait.h>

#ifndef SH_H_
    #define SH_H_
    #define green "\033[32;01m"
    #define blue "\033[34;01m"
    #define cyan "\033[36;01m"
    #define red "\033[31;01m"
    #define white "\033[29;01m"
    #define normal "\033[0m"

// All utils
char *my_search_in_env(char **env, char *search);
int return_value(int nb);
char *my_get_line(char **arr_path, char **env);
int fonction(char **env, char **arr_line, char **arr_path);
int were_is_the_path(char **env, char *search);
int segfault(pid_t pid);
int nbr_pass(int nouveauNombre);
void clean_arr(char **arr_line);
int have_and(char *line, int and_status);
void my_putstr_error(char *str);

// Implement functions
int my_cd(char **env, char **arr_line);
int my_setenv(char **env, char **arr_line);
int the_arg_anvailable(char **env, char **arr_line);
int the_arg_available(char **env, char **arr_line);
int my_setenv_cd(char **env, char *value, char *env_path);
void cd_setenv_alter(char **env, char *str, char *str2);
int my_unsetenv(char **env, char **arr_line);
void simple_redirection(char **arr_line, char *res, char **env, char *outfile);
void pipe_execve(char **arr_line, char **arr_path, char **env, int i);
char *transfer_in_maj(char *str);
void my_execve(char **arr_line, char **arr_path, char **env);
void is_parentese_commande_line(char **path);
void open_parenthese(char **path);
int i_static(int nb);

// my_echo
int my_echo(char **env, char **arr_line);
int verif_valid_path(char **env, char **arr_line);
int my_echo_path_two(char **arr_line, int i, int j, char *str);
char **env_static(char **envp);

// Main functions
void shell(char **env);
void my_prompt(char **env);
int exec_ve(char **arr_line, char **arr_path, char **env, char *outfile);

#endif /* !SH_H_ */
