/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:49:19 by aroi              #+#    #+#             */
/*   Updated: 2018/07/05 13:23:09 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_print_width_s(t_printf **printf, int size)
{
	if ((*printf)->zero)
		while ((*printf)->width - size > 0 && (*printf)->width - (*printf)->precision > 0)
		{
			write(1, " ", 1);
			(*printf)->num++;
			(*printf)->width--;
		}
	else
		while ((*printf)->width - size > 0)
		{
			write(1, " ", 1);
			(*printf)->num++;
			(*printf)->width--;
		}
}

static void		ft_uni_str_precision_n_width(t_printf **print, wchar_t *str)
{
	int			precision;
	int			size;
	int			size2;


	size = size_of_uni_str(str);
	if (size - (*print)->precision > 0 && (*print)->precision >= 0)
		size = (*print)->precision;
	size2 = size;
	if ((*print)->zero)
	{
		(*print)->precision = (*print)->width;
		(*print)->width = 0;
		precision = (*print)->precision;
	}
	else
		precision = 0;
	if (!(*print)->minus)
		ft_print_width_s(print, size);
	while (precision-- - size > 0)
	{
		write(1, "0", 1);
		(*print)->num++;
	}
	(*print)->num += size;
	while (*str && size-- > 0)
		ft_putchar(*str++);
	if ((*print)->minus)
		ft_print_width_s(print, size2);
}

static void		ft_str_precision_n_width(t_printf **print, char *str)
{
	int			precision;
	int			size;
	int			size2;

	size = size_of_str(str);
	if (size - (*print)->precision > 0 && (*print)->precision >= 0)
		size = (*print)->precision;
	size2 = size;
	if ((*print)->zero)
	{
		if ((*print)->width - (*print)->precision > 0)
			(*print)->precision = (*print)->width;
		(*print)->width = 0;
		precision = (*print)->precision;
	}
	else
		precision = 0;
	if (!(*print)->minus)
		ft_print_width_s(print, size);
	while (precision-- - size > 0)
	{
		write(1, "0", 1);
		(*print)->num++;
	}
	(*print)->num += size;
	while (*str && size-- > 0)
		ft_putchar(*str++);
	if ((*print)->minus)
		ft_print_width_s(print, size2);
}

void            ft_is_string(t_printf **printf, va_list argPointer)
{
	char	*str;
	wchar_t	*str_u;

	if (*((*printf)->str) == 's' && (*printf)->cast != L)
	{
		(*printf)->conv = 's';
		if (!(str = va_arg(argPointer, char *)))
			str = "(null)";
		ft_str_precision_n_width(printf, str);
	}
	else
	{
		(*printf)->conv = 'S';
		if (!(str_u = va_arg(argPointer, wchar_t *)))
		{
			str_u = (wchar_t *)malloc(sizeof(wchar_t) * 7);
			str_u[0] = '(';
			str_u[1] = 'n';
			str_u[2] = 'u';
			str_u[3] = 'l';
			str_u[4] = 'l';
			str_u[5] = ')';
			str_u[6] = '\0';
		}
		ft_uni_str_precision_n_width(printf, str_u);
	}
	(*printf)->str += 1;
	(*printf)->i += 1;
//	ft_strdel(&s);
}