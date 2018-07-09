/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_act.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:40:36 by aroi              #+#    #+#             */
/*   Updated: 2018/07/09 15:20:05 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_flag_activation(t_printf **printf)
{
	while (*((*printf)->str) == '#' || *((*printf)->str) == '0' ||
			*((*printf)->str) == '-' || *((*printf)->str) == '+' ||
			*((*printf)->str) == ' ' || *((*printf)->str) == '\'')
	{
		if ((*printf)->str[0] == '#')
			(*printf)->sharp = 1;
		else if ((*printf)->str[0] == '0' && !(*printf)->minus)
			(*printf)->zero = 1;
		else if ((*printf)->str[0] == '-')
		{
			(*printf)->zero = 0;
			(*printf)->minus = 1;
		}
		else if ((*printf)->str[0] == '+')
		{
			(*printf)->space = 0;
			(*printf)->plus = 1;
		}
		else if ((*printf)->str[0] == ' ' && !(*printf)->plus)
			(*printf)->space = 1;
		(*printf)->str++;
		(*printf)->i++;
	}
}

void			ft_width_activation(t_printf **print)
{
	int qnt;

	(*print)->width = ft_atoi((*print)->str);
	qnt = ft_count_digits_base((*print)->width, 10);
	while (qnt-- > 0)
	{
		(*print)->str++;
		(*print)->i++;
	}
}

void			ft_precision_activation(t_printf **print)
{
	int qnt;

	(*print)->str++;
	(*print)->i++;
	(*print)->precision = ft_atoi((*print)->str);
	qnt = ft_count_digits_base((*print)->precision, 10);
	if (!ft_isdigit(*((*print)->str)))
		qnt = 0;
	while (qnt-- > 0)
	{
		(*print)->str++;
		(*print)->i++;
	}
}

void			ft_cast_activation(t_printf **printf)
{
	while ((*printf)->str[0] == 'h' || (*printf)->str[0] == 'l' ||
			(*printf)->str[0] == 'j' || (*printf)->str[0] == 'z')
	{
		if ((*printf)->str[0] == 'z' && Z > (*printf)->cast)
			(*printf)->cast = Z;
		else if ((*printf)->str[0] == 'j' && J > (*printf)->cast)
			(*printf)->cast = J;
		else if ((*printf)->str[0] == 'l' && (*printf)->str[1] == 'l' &&
				LL > (*printf)->cast && (*printf)->str++ && (*printf)->i++)
			(*printf)->cast = LL;
		else if ((*printf)->str[0] == 'l' && L > (*printf)->cast)
			(*printf)->cast = L;
		else if ((*printf)->str[0] == 'h' && (*printf)->str[1] != 'h' &&
				H > (*printf)->cast)
			(*printf)->cast = H;
		else if (HH > (*printf)->cast)
		{
			(*printf)->cast = HH;
			(*printf)->str++;
			(*printf)->i++;
		}
		(*printf)->i++;
		(*printf)->str++;
	}
}
