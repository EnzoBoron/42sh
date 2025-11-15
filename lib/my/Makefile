##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for Lib
##

SRC = 	my_putchar.c \
		my_free_array.c \
		my_getnbr.c \
		my_open_file.c \
		my_print_array.c \
		my_putnbr.c \
		my_atof.c \
		my_abs.c \
		my_putstr.c \
		my_str_is_numb.c \
		my_str_to_word_array.c \
		my_strcmp.c \
		my_swap.c \
		my_strstr.c \
		my_strndup.c \
		my_strlen.c \
		my_strncmp.c \
		my_strcat.c \
		my_strdup.c \
		my_strcpy.c \
		my_str_is_alpha.c \
		my_sqrt.c \
		my_scientifique_converter.c \
		my_revstr.c \
		my_putfloat.c \
		my_putnbr_base.c \
		my_putadress.c \
		flag_part1.c \
		flag_part2.c \
		flag_part3.c \
		my_printf.c \
		my_pow.c \
		my_octal_converter.c \
		my_nbrlen.c \
		my_malloc_array.c \
		my_itoa.c \
		my_isneg.c \
		my_is_prime.c \
		my_hexadecimal_converter.c \
		my_find_prime_sup.c \
		my_compute_power_rec.c \
		my_binary_converter.c \
		my_atoi.c \
		my_array_len.c \
		my_free.c \
		my_clean_str.c \
		my_realloc.c \
		my_clean_str.c \

OBJ = $(SRC:.c=.o);

NAMELIB = libmy.a

CFLAGS = -I./../../include/

all:	$(NAMELIB)

$(NAMELIB): $(OBJ)
	@echo -e "\033[33;01m[--------lib-------------]\033[;0m"
	@echo -e "ar rc $(NAMELIB) $(OBJ)"
	@ar rc $(NAMELIB) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean :	clean
	@echo -e "\033[31;01m--------fclean_lib-------------\033[;0m"
	echo -e "rm -f $(NAMELIB)"
	rm -f $(NAMELIB)

re : fclean all
