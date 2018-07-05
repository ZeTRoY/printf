/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:33:30 by aroi              #+#    #+#             */
/*   Updated: 2018/07/05 16:24:30 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_sign_and_width(t_printf **printf, intmax_t i)
{
	int qnt;

	qnt = ft_count_digits_base(i, 10);
	if (i < 0 || (*printf)->plus)
		(*printf)->width--;
	else if ((*printf)->space)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

static void			ft_print_width_int(t_printf **printf, intmax_t qnt)
{
	while ((intmax_t)(*printf)->width - qnt > 0 &&
			(*printf)->width > (*printf)->precision)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

static void			ft_print_nbr(intmax_t n, int qnt)
{
	char *str;

	str = ft_itoa(n);
	if (*str == '-')
		str++;
	while (qnt-- > 0)
		write(1, str++, 1);
//	ft_strdel(&str);
}

static int			ft_di_precision_n_width(t_printf **print, intmax_t i)
{
	int	precision;
	int qnt;

	ft_sign_and_width(print, i);
	if (i == 0 && (*print)->precision >= 0)
		qnt = 0;
	else
		qnt = ft_count_digits_base(i, 10);
	if ((*print)->zero && (*print)->precision < 0)
	{
		(*print)->precision = (*print)->width;
		(*print)->width = 0;
	}
	precision = (*print)->precision;
	if (!(*print)->minus)
		ft_print_width_int(print, qnt);
	if (i < 0)
		write(1, "-", 1);
	else if ((*print)->plus)
		write(1, "+", 1);
	while (precision-- - qnt > 0)
	{
		write(1, "0", 1);
		(*print)->num++;
	}
	ft_print_nbr(i, qnt);
	if ((*print)->minus)
		ft_print_width_int(print, qnt);
	return (qnt);
}

static intmax_t	di_cast(t_printf **printf, va_list argPointer)
{
	intmax_t	i;

	i = va_arg(argPointer, intmax_t);
	if ((*printf)->cast == LL)
		i = (long long)i;
	else if ((*printf)->cast == Z)
		i = (size_t)i;
	else if ((*printf)->cast == L || *((*printf)->str) == 'D')
		i = (long)i;
	else if ((*printf)->cast != J)
		i = (int)i;
	if (*((*printf)->str) != 'D')
	{ 
		if ((*printf)->cast == H)
			i = (short)i;
		else if ((*printf)->cast == HH)
			i = (char)i;
	}
	return (i);
}

void			ft_is_decimal(t_printf **printf, va_list argPointer)
{
	int			qnt;
	intmax_t	i;
	
	if (*((*printf)->str) == 'd' || *((*printf)->str) == 'i')
		(*printf)->conv = 'd';
	else
		(*printf)->conv = 'D';
	i = di_cast(printf, argPointer);
	qnt = ft_di_precision_n_width(printf, i);
	if (i < 0 || (*printf)->plus)
		(*printf)->num++;
	while (qnt-- > 0)
		(*printf)->num++;
	(*printf)->str += 1;
	(*printf)->i += 1;
}