# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 17:42:00 by aroi              #+#    #+#              #
#    Updated: 2018/06/21 17:39:57 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRC = main.c ft_flag_act.c ft_is.c ft_itoa.c ft_itoa_base.c \
	  ft_litoa.c ft_litoa_base.c ft_uitoa.c ft_uitoa_base.c ft_putchar.c \
	  ft_putnbr.c ft_putunbr.c ft_putstr.c ft_toupper.c printf_func.c \
	  unicode.c what_is.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
