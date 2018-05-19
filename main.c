/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:18:48 by aroi              #+#    #+#             */
/*   Updated: 2018/05/19 15:50:19 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int		ft_count_qnt(char *str)
{
	int i;
	int qnt;

	i = -1;
	qnt = 0;
	if (str)
		while (str[++i])
			if (str[i] == '%' && str[i + 1] = '%' &&
		str[i - 1] != '%' && str[i + 1])
				qnt++;
	return (qnt);
}

void	ft_whatisit(char *str)
{
	int i;

	i = 0;
}

int		ft_printf(char *str, ...)
{
	int i;
	char c;
	char *tmp;
	va_list argPointer;
	int qnt;
	
	i = -1;
	qnt = ft_count_qnt(str);
	va_start(argPointer, qnt);
	while (++i < qnt)
	{
		tmp = ft_strchr(str, '%');
		ft_putstr(str - tmp);
		str = tmp + 1;
		ft_whatis(str);
	}
	ft_putstr(tmp);
	va_end(argPointer);
	return (i);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		printf("printf:    \n");
//		printf(argv);
		printf("ft_printf: \n");
//		ft_printf(argv);
	}
	return (0);
}
