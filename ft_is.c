/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 10:00:49 by aroi              #+#    #+#             */
/*   Updated: 2018/06/12 17:51:53 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void	ft_isdecimal(t_printf *printf, va_list argPointer)
{
	int i;
	
	i = va_arg(argPointer, int);
	ft_putnbr(i);
	if (i < 0)
		num++;
	while (i)
	{
		i /= 10;
		printf->num++;
	}
}

void	ft_is_s_or_c(t_printf *printf, va_list argPointer)
{
	char *s;
	int i;
	unsigned char c;

	i = 0;
	if (*(printf->str) == 's')
	{
		s = va_arg(argPointer, char *);
		while (s[i])
		{
			write(1, &s[i++], 1);
			printf->num++;
		}
	}
	else if (*(printf->str) == 'c')
	{
		c = (unsigned char)va_arg(argPointer, int);
		write(1, &c, 1);
		printf->num++;
	}
}

void	ft_base(t_printf printf, va_list argPointer)
{
	int i;
	char ch;
	char *string;

	i = -1;
	if ((unsigned char)*(printf->str) == 'o')
		string = ft_uitoa_base(va_arg(argPointer, unsigned int), 8);
	else
		string = ft_uitoa_base(va_arg(argPointer, unsigned int), 16);
	while (string[++i])
	{
		printf->num++;
		ch = (char)ft_toupper(string[i]);
		if (*(printf->str) == 'X')
			write(1, &ch, 1);
		else
			write(1, &string[i], 1);
	}
}

void	ft_what_is_love(t_printf printf, va_list argPointer)
{
	if (*(printf->str) == 'd' || *(printf->str) == 'i')
		ft_isdecimal(printf, argPointer);
	else if (*(printf->str) == 's' || *(printf->str == 'c')
		ft_is_s_or_c(printf, argPointer);
	else if (*(printf->str) == 'S')
		ft_iswchar(printf, argPointer);
	else if (*(printf->str) == 'C')
		ft_iswint(printf, argPointer);
	else if (*(printf->str) == 'o' || *(printf->str) == 'x'
			|| *(printf->str) == 'X')
		ft_base(printf, argPointer);
}
