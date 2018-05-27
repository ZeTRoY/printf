/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:18:48 by aroi              #+#    #+#             */
/*   Updated: 2018/05/27 15:23:50 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

#include <stdio.h>

void	ft_isdecimal(char *str, va_list argPointer);
void	ft_isstring(char *str, va_list argPointer);
void	ft_ischar(char *str, va_list argPointer);

void	ft_whatisit(char *str, va_list argPointer, int *j)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'd' || str[i] == 'i')
			ft_isdecimal(str, argPointer);
		else if (str[i] == 's')
			ft_isstring(str, argPointer);
		else if (str[i] == 'c')
			ft_ischar(str, argPointer);
		else if (str[i] == '%')
			write(1, "%", 1);
		else
			continue;
		*j += i + 1;
		break;
	}
}

int		ft_printf(char *str, ...)
{
	int i;
	char *tmp;
	va_list argPointer;
	
	i = 0;
	va_start(argPointer, str);
	while (str[i])
	{
		if (str[i] != '%')
			write(1, &str[i++], 1);
		else
		{
			tmp = str + ++i;
			ft_whatisit(tmp, argPointer, &i);
//			ft_putnbr(i);
		}
	}
//	while (str[i])
//		write(1, &str[i++], 1);
	va_end(argPointer);
	return (i);
}

int		main(int argc, char **argv)
{
	int	p;
	int i;

	i = 0;
	while (++i < argc)
	{
		write(1, "ft_printf: ", 11);
		p = ft_printf("%s | %s\n", argv[1], argv[2]);
		printf("p: %d\nprintf:    ", p);
		p = printf("%s | %s\n", argv[1], argv[2]);
		printf("p: %d\n", p);
	}
	return (0);
}
