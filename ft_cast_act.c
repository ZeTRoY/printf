/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_act.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:40:36 by aroi              #+#    #+#             */
/*   Updated: 2018/07/05 10:56:37 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_qnt(int n)
{
	int qnt;

	qnt = 0;
	if (n == 0)
		qnt = 1;
	while (n > 0)
	{
		n /= 10;
		qnt++;
	}
	return (qnt);
}

void			ft_flag_activation(t_printf **printf)
{
	while (*((*printf)->str) == '#' || *((*printf)->str) == '0' ||
			*((*printf)->str) == '-' || *((*printf)->str) == '+' ||
			*((*printf)->str) == ' ')
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
	qnt = ft_qnt((*print)->width);
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
	// printf("\n%d\n", (*print)->precision);
	qnt = ft_qnt((*print)->precision);
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
		if ((*printf)->str[0] == 'z' && Z >= (*printf)->cast)
			(*printf)->cast = Z;
		else if ((*printf)->str[0] == 'j' && J >= (*printf)->cast)
			(*printf)->cast = J;
		else if ((*printf)->str[0] == 'l' && (*printf)->str[1] == 'l' &&
				LL >= (*printf)->cast && (*printf)->str++ && (*printf)->i++)
			(*printf)->cast = LL;
		else if ((*printf)->str[0] == 'l' && L >= (*printf)->cast)
			(*printf)->cast = L;
		else if ((*printf)->str[0] == 'h' && (*printf)->str[1] != 'h' &&
				H >= (*printf)->cast)
			(*printf)->cast = H;
		else
		{
			(*printf)->cast = HH;
			(*printf)->str++;
			(*printf)->i++;
		}
		(*printf)->i++;
		(*printf)->str++;
	}
}
