# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 17:42:00 by aroi              #+#    #+#              #
#    Updated: 2018/07/09 13:22:46 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRC =	color.c \
		date_func.c \
		ft_atoi.c \
		ft_cast_act.c \
		ft_count_digits.c \
		ft_count_letters.c \
		ft_is.c \
		ft_is_sigil.c \
		ft_isdigit.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_pow.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strstr.c \
		ft_sqrt.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_upper.c \
		out_b.c \
		out_base.c \
		out_bin_dec.c \
		out_c.c \
		out_date.c \
		out_int.c \
		out_uint.c \
		out_n.c \
		out_o.c \
		out_s.c \
		out_sqrt.c \
		out_xp_part_one.c \
		out_xp_prt_two.c \
		printf_func.c \
		qnt_of_bits.c \
		what_is.c \
		what_is_pt_two.c

OBJ =	color.o \
		date_func.o \
		ft_atoi.o \
		ft_cast_act.o \
		ft_count_digits.o \
		ft_count_letters.o \
		ft_is.o \
		ft_is_sigil.o \
		ft_isdigit.o \
		ft_itoa.o \
		ft_itoa_base.o \
		ft_pow.o \
		ft_printf.o \
		ft_putchar.o \
		ft_putstr.o \
		ft_putnbr.o \
		ft_strdel.o \
		ft_strdup.o \
		ft_strjoin.o \
		ft_strlen.o \
		ft_strstr.o \
		ft_sqrt.o \
		ft_tolower.o \
		ft_toupper.o \
		ft_upper.o \
		out_b.o \
		out_base.o \
		out_bin_dec.o \
		out_c.o \
		out_date.o \
		out_int.o \
		out_uint.o \
		out_n.o \
		out_o.o \
		out_s.o \
		out_sqrt.o \
		out_xp_prt_one.o \
		out_xp_prt_two.o \
		printf_func.o \
		qnt_of_bits.o \
		what_is.o \
		what_is_pt_two.o

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
