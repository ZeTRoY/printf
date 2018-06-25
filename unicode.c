/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:23:46 by aroi              #+#    #+#             */
/*   Updated: 2018/06/24 19:01:45 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static intmax_t		size_of(wchar_t uni_char)
{
	if (uni_char <= _7_BITS)
		return (1);
	if (uni_char <= _11_BITS)
		return (2);
	if (uni_char <= _16_BITS)
		return (3);
	return (4);
}

static int			size_of_str(wchar_t *str)
{
	int		size;
	size_t	i;

	i = 0;
	size = 0;
	while (str[i])
		size += size_of(str[i++]);
	return (size);
}

static void			unicode(t_printf **printf, wchar_t uni_char)
{
	char	size;
	unsigned char	c[4];

	if (uni_char <= _7_BITS)
		c[0] = uni_char;
	else if (uni_char <= _11_BITS)
	{
		c[0] = (uni_char >> 6 & _00011111) | _11000000;
		c[1] = (uni_char & _00111111) | _10000000;
	}
	else if (uni_char <= _16_BITS)
	{
		c[0] = (uni_char >> 12 & _00001111) | _11100000;
		c[1] = (uni_char >> 6 & _00111111) | _10000000;
		c[2] = (uni_char & _00111111) | _10000000;
	}
	else
	{
		c[0] = (uni_char >> 18 & _00000111) | _11110000;
		c[1] = (uni_char >> 12 & _00111111) | _10000000;
		c[2] = (uni_char >> 6 & _00111111) | _10000000;
		c[3] = (uni_char & _00111111) | _10000000;
	}
	size = size_of(uni_char);
	write(1, &c, size);
	while (size-- > 0)
		(*printf)->num++;
}

static void			ft_unicode_precision_n_width(t_printf **print, wchar_t *str)
{
	int		precision;
	intmax_t	size;

	if ((*print)->zero && (*print)->precision == 0)
	{
		(*print)->precision = (*print)->width;
		(*print)->width = 0;
	}
	precision = (*print)->precision;
	size = size_of_str(str);
	if (!(*print)->minus)
		ft_print_width(print, size);
	while (precision-- - size > 0)
	{
		write(1, "0", 1);
		(*print)->num++;
	}
	while (*str)
	{
		unicode(print, *str);
		str++;
	}
	if ((*print)->minus)
		ft_print_width(print, size);
}

void	ft_is_unicode(t_printf **printf, va_list argPointer)
{
	size_t	size;
	size_t	i;
	wchar_t	*tmp;
	wchar_t	*s;

	i = 0;
	size = 0;
	if (*((*printf)->str) == 'S')
	{
		tmp = va_arg(argPointer, wchar_t *);
		if (!(s = (wchar_t *)malloc(sizeof(wchar_t) * ((size = size_of_str(tmp)) + 1))))
			return ;
		while (tmp[i++])
			s[i - 1] = tmp[i - 1];
	}
	else if (*((*printf)->str) == 'C')
	{
		if (!(s = (wchar_t *)malloc(2)))
			return ;
		s[i++] = (wchar_t)va_arg(argPointer, wint_t);
	}
	s[i] = '\0';
	ft_unicode_precision_n_width(printf, s);
	(*printf)->str += 1;
	(*printf)->i += 1;
	free(s);
}