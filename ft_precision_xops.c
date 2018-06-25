/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_xops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:20:17 by aroi              #+#    #+#             */
/*   Updated: 2018/06/24 18:50:25 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_print_width_p(t_printf **printf, int qnt)
{
	while ((*printf)->width - qnt > 0 &&
		(*printf)->width - (*printf)->precision > 2)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

void		ft_xo_precision_n_width(t_printf **printf, char *str)
{
	int		precision;
	int		qnt;

	if ((*printf)->zero && (*printf)->precision == 0)
	{
		(*printf)->precision = (*printf)->width;
		(*printf)->width = 0;
	}
	precision = (*printf)->precision;
	qnt = ft_count_letters(str);
	if (!(*printf)->minus)
		ft_print_width(printf, qnt);
	while (precision-- - qnt > 0)
	{
		write(1, "0", 1);
		(*printf)->num++;
	}
	while (*str)
	{
		(*printf)->num++;
		write(1, str, 1);
		str++;
	}
	if ((*printf)->minus)
		ft_print_width(printf, qnt);
}

void		ft_p_width(t_printf **printf, char *str)
{
	int qnt;

	if ((*printf)->zero && (*printf)->precision == 0)
	{
		(*printf)->precision = (*printf)->width;
		(*printf)->width = 0;
	}
	qnt = ft_count_letters(str);
	if (!(*printf)->minus)
		ft_print_width_p(printf, qnt);
}

void		ft_p_precision(t_printf **printf, char *str)
{
	int		precision;
	int		qnt;

	precision = (*printf)->precision;
	qnt = ft_count_letters(str);
	if (*((*printf)->str) == 'p' || (*printf)->sharp)
	{
		write(1, "0x", 2);
		(*printf)->num += 2;
		if ((*printf)->zero)
			(*printf)->width -= 2;
		else
			precision -= 2;
	}
	while (precision-- - qnt > 0)
	{
		write(1, "0", 1);
		(*printf)->num++;
	}
	while (*str)
	{
		(*printf)->num++;
		write(1, str, 1);
		str++;
	}
	if ((*printf)->minus)
		ft_print_width_p(printf, qnt);
}

void		ft_str_precision_n_width(t_printf **printf, char *str)
{
	int precision;
	int qnt;

	if ((*printf)->zero && (*printf)->precision == 0)
	{
		(*printf)->precision = (*printf)->width;
		(*printf)->width = 0;
	}
	else
		(*printf)->precision = 0;
	precision = (*printf)->precision;
	qnt = ft_count_letters(str);
	if (!(*printf)->minus)
		ft_print_width(printf, qnt);
	while ((*printf)->zero && precision-- - qnt > 0)
	{
		write(1, "0", 1);
		(*printf)->num++;
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		(*printf)->num++;
	}
	if ((*printf)->minus)
		ft_print_width(printf, qnt);
}
