# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 17:42:00 by aroi              #+#    #+#              #
#    Updated: 2018/07/05 10:19:34 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRC =	ft_atoi.c \
		ft_cast_act.c \
		ft_count_digits.c \
		ft_count_letters.c \
		ft_is.c \
		ft_isdigit.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_toupper.c \
		out_c.c \
		out_int.c \
		out_uint.c \
		out_o.c \
		out_s.c \
		out_xp.c \
		printf_func.c \
		qnt_of_bits.c \
		what_is.c

OBJ =	ft_atoi.o \
		ft_cast_act.o \
		ft_count_digits.o \
		ft_count_letters.o \
		ft_is.o \
		ft_isdigit.o \
		ft_itoa.o \
		ft_itoa_base.o \
		ft_printf.o \
		ft_putchar.o \
		ft_putstr.o \
		ft_putnbr.o \
		ft_strdel.o \
		ft_strdup.o \
		ft_strjoin.o \
		ft_strlen.o \
		ft_toupper.o \
		out_c.o \
		out_int.o \
		out_uint.o \
		out_o.o \
		out_s.o \
		out_xp.o \
		printf_func.o \
		qnt_of_bits.o \
		what_is.o

%.o: %.c
	@$(CC) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
