/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:18:48 by aroi              #+#    #+#             */
/*   Updated: 2018/06/12 17:53:03 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "printf.h"

#include "libft.h"
#include <stdio.h>

void	ft_what_is_it(t_printf *printf, va_list argPointer)
{
	while (*printf->str)
	{
		if (is_flag(printf->str))
			ft_flag_activation(printf);
		if (is_flag_size(printf->str))
			ft_flag_size_activation(printf);
		if (is_conversion(printf->str))
			ft_wahtislove(printf, argPointer);
		else if (printf->str[i])
		{
			printf->num++;
			write(1, "%", 1);
			printf->i += 2;
			printf->str += 2;
		}
	}
}

int		ft_printf(char *str, ...)
{
	t_printf	*printf;
	va_list		argPointer;
	
	printf = new_printf();
	va_start(argPointer, str);
	while (str[printf->i])
	{
		if (str[printf->i] != '%')
		{
			printf->num++;
			write(1, &str[printf->i++], 1);
		}
		else if (str[printf->i + 1] != '%')
		{
			printf->str = str + ++printf->i;
			ft_what_is_it(printf, argPointer);
		}
	}
	va_end(argPointer);
	return (printf->num);
}

int		main(int argc, char **argv)
{
	int	p;
	int i;

	i = 0;
	while (++i < argc)
	{
		write(1, "ft_printf: ", 11);
		p = ft_printf("%c | %i | %s | %% | %o | %x | %X\n", 'a', 10, argv[1], -64, -16, -27678);
		printf("p: %d\nprintf:    ", p);
		p = printf("%c | %#i | %s | %% | %o | %x | %X\n", 'a', 10, argv[1], -64, -16, -27678);
		printf("p: %d\n", p);
		write(1, "=================================", 33);
		write(1, "=================================", 33);
		write(1, "==============\n", 15);
		write(1, "ft_printf: ", 11);
//		p = ft_printf("%C | %S\n", 20, argv[1]);
		printf("p: %d\nprintf:    ", p);
//		p = printf("%C | %S\n", 20, argv[1]);
		printf("p: %d\n", p);

	}
	return (0);
}
