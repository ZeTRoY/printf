/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:18:48 by aroi              #+#    #+#             */
/*   Updated: 2018/06/24 18:40:31 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_what_is_it(t_printf **print, va_list argPointer)
{
	char *str;

	if (is_flag((*print)->str))
		ft_flag_activation(print);
	if (is_width((*print)->str))
		ft_width_activation(print);
	if (is_precision((*print)->str))
		ft_precision_activation(print);
	if (is_cast((*print)->str))
		ft_cast_activation(print);
	if (is_conversion((*print)->str))
		ft_what_is_love(print, argPointer);
	else if (*((*print)->str))
	{
		(*print)->num++;
		write(1, "%", 1);
		(*print)->i++;
		(*print)->str += 2;
	}
}

int		ft_printf(char *str, ...)
{
	t_printf	*printf;
	va_list		argPointer;
	char		c;

	printf = new_printf();
	va_start(argPointer, str);
	while (str[printf->i])
	{
		if (str[printf->i] != '%')
		{
			printf->num++;
			write(1, &str[printf->i++], 1);
		}
		else
		{
			ft_printf_update(&printf);
			printf->str = str + ++printf->i;
			ft_what_is_it(&printf, argPointer);
		}
	}
	va_end(argPointer);
	return (printf->num);
}
