/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:18:48 by aroi              #+#    #+#             */
/*   Updated: 2018/06/21 17:22:37 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdio.h>

void	ft_what_is_it(t_printf **printf, va_list argPointer)
{
	char *str;

	if (is_flag((*printf)->str))
		ft_flag_activation(printf);
//	if (is_size_flag(printf->str))
//		ft_flag_size_activation(printf);
	if (is_conversion((*printf)->str))
		ft_what_is_love(printf, argPointer);
	else if (*((*printf)->str))
	{
		(*printf)->num++;
		write(1, "%", 1);
		(*printf)->i++;
		(*printf)->str += 2;
	}
}

int		ft_printf(char *str, ...)
{
	t_printf	*printf;
	va_list		argPointer;
	char c;

	printf = new_printf();
	va_start(argPointer, str);
	while (str[printf->i])
	{
		if (str[printf->i] != '%')
		{
			printf->num++;
			write(1, &str[printf->i++], 1);
		}
		else
		{
			printf->str = str + ++printf->i;
			ft_what_is_it(&printf, argPointer);
		}
	}
	va_end(argPointer);
	return (printf->num);
}

#include <locale.h>

int		main(int argc, char **argv)
{
	setlocale(LC_ALL, "");
	int	p;
	int i;
	int	str[5];
	int c1 = L'Ǽ';
	int c2 = L'💩';
	int c3 = L'🌚';

	i = 0;
	str[0] = c1;
	str[1] = c2;
	str[2] = c3;
	str[3] = c1;
	str[4] = 0;
	if (argc > 1)
	{
		write(1, "ft_printf: ", 11);
		p = ft_printf("%c | %i | %D | %u | %U | %s | %% | %o | %x | %X | %C | %p | %S\n", 'a', 10, -1, -1, -1, argv[1], -64, -16, 111111111111, c1, str, str);
		printf("p: %d\nprintf:    ", p);
		p = printf("%c | %i | %D | %u | %U | %s | %% | %o | %x | %X | %C | %p | %S\n", 'a', 10, -1, -1, -1, argv[1], -64, -16, 111111111111, c1, str, str);
		printf("p: %d\n", p);
		write(1, "=================================", 33);
		write(1, "=================================", 33);
		write(1, "==============\n", 15);
		ft_printf("%D\n", -1);
		printf("%li\n", -1);
//		write(1, "ft_printf: ", 11);
//		p = ft_printf("%C | %S\n", 20, argv[1]);
//		printf("p: %d\nprintf:    ", p);
//		p = printf("%C | %S\n", 20, argv[1]);
//		printf("p: %d\n", p);

	}
	return (0);
}
