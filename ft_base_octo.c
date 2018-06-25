/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_octo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 20:40:19 by aroi              #+#    #+#             */
/*   Updated: 2018/06/24 16:24:44 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_base_octo(t_printf **printf, va_list argPointer)
{
	size_t	i;
	char	*str;
	char	*tmp;

	i = 0;
	if (*((*printf)->str) == 'O')
		str = ft_itoa_base(va_arg(argPointer, unsigned long), 8);
	else
		str = ft_itoa_base(va_arg(argPointer, unsigned int), 8);
	if ((*printf)->sharp)
	{
		tmp = ft_strjoin("0", str);
		ft_strdel(&str);
		str = tmp;
	}
	ft_xo_precision_n_width(printf, str);
	(*printf)->str++;
	(*printf)->i++;
}
