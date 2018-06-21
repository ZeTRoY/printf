/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:23:46 by aroi              #+#    #+#             */
/*   Updated: 2018/06/21 17:10:40 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "printf.h"
#define _00000111 7
#define _00001111 15
#define _00011111 31
#define _00111111 63
#define _10000000 128
#define _11000000 192
#define _11100000 224
#define _11110000 240

void			unicode(t_printf **printf, int uni_char)
{
	char	size;
	char	c[4];

	if (uni_char <= 127)
	{
		c[0] = uni_char;
		size = 1;
	}
	else if (uni_char <= 2047)
	{
		c[0] = (uni_char >> 6 & _00011111) | _11000000;
		c[1] = (uni_char & _00111111) | _10000000;
		size = 2;
	}
	else if (uni_char <= 65535)
	{
		c[0] = (uni_char >> 12 & _00001111) | _11100000;
		c[1] = (uni_char >> 6 & _00111111) | _10000000;
		c[2] = (uni_char & _00111111) | _10000000;
		size = 3;
	}
	else
	{
		c[0] = (uni_char >> 18 & _00000111) | _11110000;
		c[1] = (uni_char >> 12 & _00111111) | _10000000;
		c[2] = (uni_char >> 6 & _00111111) | _10000000;
		c[3] = (uni_char & _00111111) | _10000000;
		size = 4;
	}
	write(1, &c, size);
	while (size-- > 0)
		(*printf)->num++;
	(*printf)->str++;
	(*printf)->i++;
}

void			ft_is_C_or_S(t_printf **printf, va_list argPointer)
{
	int		i;
	int		*str;

	i = -1;
	if (*((*printf)->str) == 'S')
	{
		str = va_arg(argPointer, int *);
		while (str[++i])
			unicode(printf, str[i]);
	}
	else
		unicode(printf, va_arg(argPointer, int));
}
