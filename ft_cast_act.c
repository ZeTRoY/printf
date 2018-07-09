/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_act.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:40:36 by aroi              #+#    #+#             */
/*   Updated: 2018/07/09 10:51:47 by aroi             ###   ########.fr       */
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
		else if ((*printf)->str[0] == '\'')
			(*printf)->apostrophe = 1;
		(*printf)->str++;
		(*printf)->i++;
	}
}

void			ft_width_activation(t_printf **print, va_list apointer)
{
	int qnt;

	if (*((*print)->str) == 42)
	{
		if (((*print)->width = va_arg(apointer, int)) < 0)
		{
			(*print)->minus = 1;
			(*print)->width = -(*print)->width;
		}
		(*print)->str++;
		(*print)->i++;
	}
	else
	{
		(*print)->width = ft_atoi((*print)->str);
		qnt = ft_count_digits_base((*print)->width, 10);
		while (qnt-- > 0)
		{
			(*print)->str++;
			(*print)->i++;
		}
	}
}

void			ft_precision_activation(t_printf **print,
					va_list apointer)
{
	int qnt;

	(*print)->str++;
	(*print)->i++;
	if (*((*print)->str) == 42)
	{
		if (((*print)->precision = va_arg(apointer, int)) < 0)
			(*print)->precision = -1;
		(*print)->str++;
		(*print)->i++;
	}
	else
	{
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
