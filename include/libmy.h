/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** Libmy created by Julien, 2023
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef LIBMY_H_
    #define LIBMY_H_

typedef enum {
    STRING,
    STRING_ARRAY
} ArgumentType;

int flag_i (va_list ap);
int flag_d (va_list ap);
int flag_s (va_list ap);
int flag_c (va_list ap);
int flag_u (va_list ap);
int flag_o (va_list ap);
int flag_pourcent (va_list ap);
int flag_x (va_list ap);
int flag_xx (va_list ap);
int flag_f (va_list ap);
int flag_e (va_list ap);
int flag_ee (va_list ap);
int flag_p (va_list ap);
int flag_b (va_list ap);
char *my_clean_str(char *str);
void my_putchar(char c);
void my_free_array(char **array);
int my_getnbr(char const *str);
char *my_open_file(char const *filepath);
void my_print_array(char **array);
void my_putnbr(int nb);
float my_atof(char *str);
void *my_realloc(char *str, int size);
int my_abs(int nb);
void my_putstr(char const *str);
int my_str_is_numb(char *str);
char **my_str_to_word_array(char const *str, char c);
int my_strcmp(char const *s1, char const *s2);
int my_swap(int *a, int *b);
char *my_strstr(char *str, char *to_find);
char *my_strndup(char const *src, int n);
int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
int my_str_is_alpha(char *str);
double my_sqrt(double n);
int my_scientifique_converter(double nb, int maj);
char *my_revstr(char *str);
void my_putfloat(double n, int prec);
int my_putnbr_base(long nb, char const *base);
void my_putadress(void *adress);
int my_printf(const char *typ_flag , ...);
double my_pow(double nb, int p);
int my_octal_converter(int nb);
int my_nbrlen(int nb);
char **my_malloc_array(int nb_rows, int nb_cols);
char *my_itoa(int number);
void my_isneg(int n);
int my_is_prime(int nb);
char *my_hexadecimal_converter(int nb, int maj);
int my_find_prime_sup(int nb);
int my_compute_power_rec(int nb, int p);
int my_binary_converter(int nb);
int my_atoi(char const *str);
int my_array_len(char **arr);
void my_free(int count, ...);

#endif /* !LIBMY_H_ */
