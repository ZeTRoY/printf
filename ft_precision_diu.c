/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_diu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 21:13:13 by aroi              #+#    #+#             */
/*   Updated: 2018/06/24 18:55:20 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

static void		ft_sign_and_width(t_printf **printf, intmax_t i)
{
	int qnt;

	qnt = ft_count_digits(i);
	if (i < 0 || ((*printf)->plus &&
			*((*printf)->str) != 'u' && *((*printf)->str) != 'U'))
		(*printf)->width--;
	else if ((*printf)->space && (*((*printf)->str) == 'i' ||
		*((*printf)->str) == 'd') && (*printf)->width - qnt <= 0)
	{
		if ((*printf)->precision > qnt)
			(*printf)->width = (*printf)->precision + qnt;
		else
			(*printf)->width = qnt + 1;
	}
}

void			ft_print_width(t_printf **printf, intmax_t qnt)
{
	while ((intmax_t)(*printf)->width - qnt > 0 &&
			(*printf)->width > (*printf)->precision)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

static void			ft_putnbr_w_o(intmax_t n)
{
	char *str;

	str = ft_itoa(n);
	if (*str == '-')
		str++;
	while (*str)
		write(1, str++, 1);
//	ft_strdel(&str);
}

void			ft_diu_precision_n_width(t_printf **print, intmax_t i)
{
	int	precision;
	int qnt;

	ft_sign_and_width(print, i);
	if ((*print)->zero && !(*print)->precision)
	{
		(*print)->precision = (*print)->width;
		(*print)->width = 0;
	}
	// printf("\n%d\n", (*print)->precision);
	qnt = ft_count_digits(i);
	precision = (*print)->precision;
	if (!(*print)->minus)
		ft_print_width(print, qnt);
	if (i < 0)
		write(1, "-", 1);
	else if ((*print)->plus &&
			*((*print)->str) != 'u' && *((*print)->str) != 'U')
		write(1, "+", 1);
	while (precision-- - qnt > 0)
	{
		write(1, "0", 1);
		(*print)->num++;
	}
	ft_putnbr_w_o(i);
	if ((*print)->minus)
		ft_print_width(print, qnt);
}
