/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_xp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:46:08 by aroi              #+#    #+#             */
/*   Updated: 2018/07/05 16:46:57 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static uintmax_t	ft_cast(t_printf **printf, va_list argPointer)
{
	uintmax_t	z;

	if (*((*printf)->str) == 'p' || (*printf)->cast == L)
		z = va_arg(argPointer, unsigned long);
	else if ((*printf)->cast == LL)
		z = va_arg(argPointer, unsigned long long);
	else if ((*printf)->cast == J)
		z = va_arg(argPointer, uintmax_t);
	else if ((*printf)->cast == Z)
		z = va_arg(argPointer, size_t);
	else
		z = va_arg(argPointer, unsigned int);
	if (*((*printf)->str) != 'p')
	{
	if ((*printf)->cast == H)
		z = (unsigned short)z;
	else if ((*printf)->cast == HH)
		z = (unsigned char)z;
	}
	return (z);
}

static void	ft_print_width_x(t_printf **printf, int qnt)
{
	while ((*printf)->width - qnt > 0 &&
		(*printf)->width - (*printf)->precision > 0)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

static int		ft_p_width(t_printf **printf, char *str, uintmax_t z)
{
	int qnt;

	qnt = ft_count_letters(str);
	if ((*printf)->zero)
	{
		if ((*printf)->width > 0)
			(*printf)->precision = (*printf)->width;
		else
			(*printf)->precision = 1;
		(*printf)->width = 0;
	}
	if (!(*printf)->minus)
	{
		if ((*printf)->conv == 'p' || z != 0)
		{ 
			while ((*printf)->width - qnt > 0 &&
				(*printf)->width - (*printf)->precision > 2)
			{
				write(1, " ", 1);
				(*printf)->num++;
				(*printf)->width--;
			}
		}
		else
			ft_print_width_x(printf, qnt);
	}
	return (qnt);
}

static void		ft_p_precision(t_printf **printf, char *str, uintmax_t z, int qnt)
{
	int		precision;
	int 	qnt2;

	precision = (*printf)->precision;
	if (*((*printf)->str) == 'p' || ((*printf)->sharp && z != 0))
	{
		write(1, str, 2);
		(*printf)->num += 2;
		if ((*printf)->zero)
			(*printf)->width -= 2;
	}
	str += 2;
	qnt2 = qnt;
	while (precision - qnt > 0)
	{
		write(1, "0", 1);
		(*printf)->num++;
		precision--;
	}
	while ((z != 0 || (*printf)->precision != 0) && *str)
	{
		(*printf)->num++;
		write(1, str, 1);
		str++;
	}
	if ((*printf)->minus)
	{
		if ((*printf)->conv == 'p' || z != 0)
		{ 
			while ((*printf)->width - qnt > 0 &&
				(*printf)->width - (*printf)->precision > 2)
			{
				write(1, " ", 1);
				(*printf)->num++;
				(*printf)->width--;
			}
		}
		else
			ft_print_width_x(printf, qnt);
	}
}

static void	zerox(t_printf **printf, va_list argPointer)
{
	intmax_t	z;
	char		*string;
	size_t		i;
	int 		qnt;

	i = 0;
	z = ft_cast(printf, argPointer);
	string = ft_strjoin("0x", ft_uitoa_base(z, 16));
	while (*((*printf)->str) == 'X' && string[++i])
		string[i] = ft_toupper(string[i]);
	qnt = ft_p_width(printf, string, z);
	ft_p_precision(printf, string, z, qnt);
//	ft_strdel(&string);
}

static void		ft_x_precision_n_width(t_printf **printf, char *str, uintmax_t z)
{
	int		precision;
	int		qnt;

	if ((*printf)->zero)
	{
		(*printf)->precision = (*printf)->width;
		(*printf)->width = 0;
	}
	precision = (*printf)->precision;
	if ((*printf)->precision >= 0 && !z)
		qnt = 0;
	else
		qnt = ft_count_letters(str);
	if (!(*printf)->minus)
		ft_print_width_x(printf, qnt);
	while (precision-- - qnt > 0)
	{
		write(1, "0", 1);
		(*printf)->num++;
	}
	while (qnt > 0 && *str)
	{
		(*printf)->num++;
		write(1, str, 1);
		str++;
	}
	if ((*printf)->minus)
		ft_print_width_x(printf, qnt);
}

void		ft_base_hexa(t_printf **print, va_list argPointer)
{
	uintmax_t	z;
	size_t		i;
	char		*string;

	i = 0;
	if (*((*print)->str) == 'p')
		(*print)->conv = 'p';
	else if (*((*print)->str) == 'x')
		(*print)->conv = 'x';
	else 
		(*print)->conv = 'X';
	if (*((*print)->str) != 'p' && !(*print)->sharp)
	{
		z = ft_cast(print, argPointer);
		string = ft_uitoa_base(z, 16);
		while (*((*print)->str) == 'X' && string[i++])
			string[i - 1] = ft_toupper(string[i - 1]);
		ft_x_precision_n_width(print, string, z);
	}
	else
		zerox(print, argPointer);
	(*print)->str += 1;
	(*print)->i += 1;
//	ft_strdel(&string);
}