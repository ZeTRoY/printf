/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:23:46 by aroi              #+#    #+#             */
/*   Updated: 2018/06/13 16:56:16 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#define _10000000 128
#define _11000000 192
#define _11100000 224
#define _11110000 240


void			unicode(t_printf **printf, va_list argPointer)
{
	char	size;
	int		i;
	char	c[4];

	i = va_arg(argPointer, int);
	if (i <= 127)
	{
		c[0] = i;
		size = 1;
	}
	else if (i <= 2047)
	{
		c[0] = (i & ~_11000000) | _10000000;
		c[1] = ;
		size = 2;
	}
	else if (i <= 65535)
	{
		c[0] = ;
		c[1] = ;
		c[2] = ;
		size = 3;
	}
	else
	{
		c[0] = ;
		c[1] = ;
		c[2] = ;
		c[3] = ;
		size = 4;
	}
	write(1, &c, size);
	(*printf)->str++;
	(*printf)->i++;
}
