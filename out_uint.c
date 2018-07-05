/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 10:20:09 by aroi              #+#    #+#             */
/*   Updated: 2018/07/05 16:35:45 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_print_width(t_printf **printf, int qnt)
{
	while ((*printf)->width - qnt > 0 &&
			(*printf)->width > (*printf)->precision)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

static void			ft_print_nbr(uintmax_t n, int qnt)
{
	char *str;

	str = ft_uitoa(n);
	while (qnt-- > 0)
		write(1, str++, 1);
//	ft_strdel(&str);
}

static int			ft_u_precision_n_width(t_printf **print, uintmax_t i)
{
	int	precision;
	int qnt;

	if (i == 0 && (*print)->precision >= 0)
		qnt = 0;
	else
		qnt = ft_count_udigits_base(i, 10);
	if ((*print)->zero && (*print)->precision < 0)
	{
		(*print)->precision = (*print)->width;
		(*print)->width = 0;
	}
	precision = (*print)->precision;
	if (!(*print)->minus)
		ft_print_width(print, qnt);
	while (precision-- - qnt > 0)
	{
		write(1, "0", 1);
		(*print)->num++;
	}
	ft_print_nbr(i, qnt);
	if ((*print)->minus)
		ft_print_width(print, qnt);
	return (qnt);
}

static uintmax_t	u_cast(t_printf **printf, va_list argPointer)
{
	uintmax_t	i;

	i = va_arg(argPointer, size_t);
	if ((*printf)->cast == LL)
		i = (unsigned long long)i;
	else if ((*printf)->cast == J)
		i = (uintmax_t)i;
	else if ((*printf)->cast == L || *((*printf)->str) == 'U')
		i = (unsigned long)i;
	else if ((*printf)->cast != Z)
		i = (unsigned int)i;
	if (*((*printf)->str) == 'u')
	{
		if ((*printf)->cast == H)
			i = (unsigned short)i;
		else if ((*printf)->cast == HH)
			i = (unsigned char)i;
	}
	return (i);
}

void			ft_is_unsigned(t_printf **print, va_list argPointer)
{
	int			qnt;
	uintmax_t	i;
	
	if (*((*print)->str) == 'u')
		(*print)->conv = 'u';
	else
		(*print)->conv = 'U';
	i = u_cast(print, argPointer);
	qnt = ft_u_precision_n_width(print, i);
	while (qnt-- > 0)
		(*print)->num++;
	(*print)->str += 1;
	(*print)->i += 1;
}