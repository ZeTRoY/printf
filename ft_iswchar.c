/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:53:35 by aroi              #+#    #+#             */
/*   Updated: 2018/06/10 14:51:23 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>
#include "libft.h"

void	ft_iswint(char *str, va_list argPointer, int *num)
{
	wchar_t c;

	c = (wchar_t)va_arg(argPointer, wint_t);
	(*num)++;
	write(1, &c, 1);
}

void	ft_iswchar(char *str, va_list argPointer, int *num)
{
	wint_t i;
	wchar_t *string;

	i = 0;
	string = va_arg(argPointer, wchar_t *);
	while (string[i])
	{
		(*num)++;
		write(1, &string[i++], 1);
	}
}
