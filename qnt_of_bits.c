/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qnt_of_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:16:21 by aroi              #+#    #+#             */
/*   Updated: 2018/07/05 17:33:46 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			size_of_uni_str(wchar_t *str)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (str[i])
		size += size_of(str[i++]);
	return (size);
}

int			size_of_str(char *str)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (str[i])
		size += size_of(str[i++]);
	return (size);
}

char		size_of(wchar_t c)
{
	if (c <= _7_BITS || MB_CUR_MAX != 4)
		return (1);
	if (c <= _11_BITS)
		return (2);
	if (c <= _16_BITS)
		return (3);
	return (4);
}
