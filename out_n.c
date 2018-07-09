/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:40:10 by aroi              #+#    #+#             */
/*   Updated: 2018/07/09 14:10:53 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_is_nbr_of_c(t_printf **printf, va_list apointer)
{
	int		*n;

	while ((*printf)->sigil-- > 0)
		n = va_arg(apointer, int *);
	*n = (*printf)->num;
	(*printf)->str++;
	(*printf)->i++;
}
