/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:44:34 by aroi              #+#    #+#             */
/*   Updated: 2018/06/24 14:50:35 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

intmax_t	di_cast(t_printf **printf, intmax_t d)
{
	intmax_t	max;

	if ((*printf)->cast == H)
		max = (short)d;
	else if ((*printf)->cast == HH)
		max = (char)d;
	else if ((*printf)->cast == L)
		max = (long)d;
	else if ((*printf)->cast == LL)
		max = (long long)d;
	else if ((*printf)->cast == J)
		max = (intmax_t)d;
	else if ((*printf)->cast == Z)
		max = (size_t)d;
	else
		max = d;
	return (max);
}
