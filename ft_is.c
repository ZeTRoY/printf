/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 10:00:49 by aroi              #+#    #+#             */
/*   Updated: 2018/07/09 15:25:54 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_what_is_love(t_printf **printf, va_list apointer)
{
	if (*((*printf)->str) == 'd' || *((*printf)->str) == 'i' ||
			*((*printf)->str) == 'D')
		ft_is_decimal(printf, apointer);
	else if (*((*printf)->str) == 'o' || *((*printf)->str) == 'O')
		ft_is_octo(printf, apointer);
	else if (*((*printf)->str) == 'u' || *((*printf)->str) == 'U')
		ft_is_unsigned(printf, apointer);
	else if (*((*printf)->str) == 'x'
			|| *((*printf)->str) == 'X' || *((*printf)->str) == 'p')
		ft_is_hexa(printf, apointer);
	else if (*((*printf)->str) == 'c' || *((*printf)->str) == 'C')
		ft_is_char(printf, apointer);
	else if (*((*printf)->str) == 's' || *((*printf)->str) == 'S')
		ft_is_string(printf, apointer);
}
