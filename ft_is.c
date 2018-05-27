/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 10:00:49 by aroi              #+#    #+#             */
/*   Updated: 2018/05/27 10:52:33 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
void	ft_isdecimal(char *str, va_list argPointer)
{
	int d;

	d = va_arg(argPointer, int);
	ft_putnbr(d);
}

void	ft_isstring(char *str, va_list argPointer)
{
	char *s;
	int i;

	i = 0;
	s = va_arg(argPointer, char *);
	while (s[i])
		write(1, &s[i++], 1);
}

void	ft_ischar(char *str, va_list argPointer)
{
	unsigned char c;

	c = (unsigned char)va_arg(argPointer, int);
	write(1, &c, 1);
}
