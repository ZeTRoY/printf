/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 10:00:49 by aroi              #+#    #+#             */
/*   Updated: 2018/06/21 17:05:46 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	ft_isdecimal(t_printf **printf, va_list argPointer)
{
	long int	l;
	int			i;
	
	if (*((*printf)->str) != 'D')
	{
		i = va_arg(argPointer, int);
		ft_putnbr(i);
		if (i < 0)
			(*printf)->num++;
		while (i)
		{
			i /= 10;
			(*printf)->num++;
		}
	}
	else
	{
		l = va_arg(argPointer, unsigned long);
		ft_putunbr(l);
		while (l)
		{
			l /= 10;
			(*printf)->num++;
		}
	}
	(*printf)->str += 1;
	(*printf)->i += 1;
}

void	ft_is_unsigned(t_printf **printf, va_list argPointer)
{
	unsigned int	u;
	unsigned long	ul;
	if (*((*printf)->str) != 'U')
	{
		u = va_arg(argPointer, unsigned int);
		ft_putunbr(u);
		while (u)
		{
			u /= 10;
			(*printf)->num++;
		}
	}
	else
	{
		ul = va_arg(argPointer, unsigned long);
		ft_putunbr(ul);
		while (ul)
		{
			ul /= 10;
			(*printf)->num++;
		}
}
	(*printf)->str++;
	(*printf)->i++;
}

void	ft_is_s_or_c(t_printf **printf, va_list argPointer)
{
	char *s;
	int i;
	unsigned char c;

	i = 0;
	if (*((*printf)->str) == 's')
	{
		s = va_arg(argPointer, char *);
		while (s[i])
		{
			write(1, &s[i++], 1);
			(*printf)->num++;
		}
	}
	else if (*((*printf)->str) == 'c')
	{
		c = (unsigned char)va_arg(argPointer, int);
		write(1, &c, 1);
		(*printf)->num++;
	}
	(*printf)->str += 1;
	(*printf)->i += 1;
}

void	ft_base(t_printf **printf, va_list argPointer)
{
	size_t i;
	char ch;
	char *string;

	i = -1;
	if ((unsigned char)*((*printf)->str) == 'o')
		string = ft_uitoa_base(va_arg(argPointer, size_t), 8);
	else if ((unsigned char)*((*printf)->str) != 'p')
		string = ft_uitoa_base(va_arg(argPointer, unsigned int), 16);
	else
	{
		string = ft_litoa_base(va_arg(argPointer, unsigned long long), 16);
		write(1, "0x", 2);
		(*printf)->num += 2;
	}
	while (string[++i])
	{
		(*printf)->num++;
		ch = (char)ft_toupper(string[i]);
		if (*((*printf)->str) == 'X')
			write(1, &ch, 1);
		else
			write(1, &string[i], 1);
	}
	(*printf)->str += 1;
	(*printf)->i += 1;
}

void	ft_what_is_love(t_printf **printf, va_list argPointer)
{
	if (*((*printf)->str) == 'd' || *((*printf)->str) == 'i'
			|| *((*printf)->str) == 'D')
		ft_isdecimal(printf, argPointer);
	else if (*((*printf)->str) == 's' || *((*printf)->str) == 'c')
		ft_is_s_or_c(printf, argPointer);
	else if (*((*printf)->str) == 'u' || *((*printf)->str) == 'U')
		ft_is_unsigned(printf, argPointer);
	else if (*((*printf)->str) == 'C' || *((*printf)->str) == 'S')
		ft_is_C_or_S(printf, argPointer);
	else if (*((*printf)->str) == 'o' || *((*printf)->str) == 'x'
			|| *((*printf)->str) == 'X' || *((*printf)->str) == 'p')
		ft_base(printf, argPointer);
}
