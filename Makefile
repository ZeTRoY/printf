# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 17:42:00 by aroi              #+#    #+#              #
#    Updated: 2018/06/21 20:57:50 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRC = ft_isdigit.c ft_atoi.c ft_printf.c ft_flag_act.c ft_is.c ft_itoa.c \
	  ft_itoa_base.c ft_litoa.c ft_litoa_base.c ft_uitoa.c ft_uitoa_base.c \
	  ft_putchar.c ft_putnbr.c ft_putunbr.c ft_putstr.c ft_toupper.c \
	  printf_func.c unicode.c what_is.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) -c $(SRC)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
