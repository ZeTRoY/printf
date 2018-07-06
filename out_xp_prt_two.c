/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_xp_prt_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:40:44 by aroi              #+#    #+#             */
/*   Updated: 2018/07/06 17:31:55 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_print_width_x(t_printf **printf, int qnt)
{
	while ((*printf)->width - qnt > 0 &&
		(*printf)->width - (*printf)->precision > 0)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

static void		ft_print_width_xp(t_printf **printf, uintmax_t z, int qnt)
{
	if (!(*printf)->minus)
	{
		if ((*printf)->conv == 'p' || z != 0)
		{
			while ((*printf)->width - qnt > 0 &&
				(*printf)->width - (*printf)->precision > 2 &&
					++(*printf)->num)
			{
				write(1, " ", 1);
				(*printf)->width--;
			}
		}
		else
			ft_print_width_x(printf, qnt);
	}
}

int				ft_p_width(t_printf **printf, char *str, uintmax_t z)
{
	int qnt;

	if ((*printf)->precision > -1 &&
			(*printf)->precision - (*printf)->width > 0)
		qnt = ft_count_letters(str) - 2;
	else
		qnt = ft_count_letters(str);
	if ((*printf)->zero)
	{
		(*printf)->precision = (*printf)->width > 0 ? (*printf)->width : 1;
		(*printf)->width = 0;
	}
	ft_print_width_xp(printf, z, qnt);
	return (qnt);
}

static void		ft_write_after(t_printf **printf, uintmax_t z, int qnt)
{
	if ((*printf)->conv == 'p' || z != 0)
	{
		while ((*printf)->width - qnt > 0 &&
			(*printf)->width - (*printf)->precision > 2)
		{
			write(1, " ", 1);
			(*printf)->num++;
			(*printf)->width--;
		}
	}
	else
		ft_print_width_x(printf, qnt);
}

void			ft_p_precision(t_printf **printf, char *str,
						uintmax_t z, int qnt)
{
	int		precision;

	precision = (*printf)->precision;
	if (*((*printf)->str) == 'p' || ((*printf)->sharp && z != 0))
	{
		write(1, str, 2);
		(*printf)->num += 2;
		if ((*printf)->zero)
			(*printf)->width -= 2;
	}
	str += 2;
	while (precision - qnt > 0 && ++(*printf)->num)
	{
		write(1, "0", 1);
		precision--;
	}
	while ((z != 0 || (*printf)->precision != 0) && *str &&
			++(*printf)->num)
		write(1, str++, 1);
	if ((*printf)->minus)
		ft_write_after(printf, z, qnt);
}
