/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 10:00:49 by aroi              #+#    #+#             */
/*   Updated: 2018/06/24 18:39:41 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_isdecimal(t_printf **printf, va_list argPointer)
{
	intmax_t		i;
	
	if (*((*printf)->str) == 'd' || *((*printf)->str) == 'i')
		i = va_arg(argPointer, int);
	else if (*((*printf)->str) == 'D')
		i = va_arg(argPointer, unsigned long);
	else if (*((*printf)->str) == 'u')
		i = va_arg(argPointer, unsigned int);
	else
		i = va_arg(argPointer, unsigned long);
	i = di_cast(printf, i);
	ft_diu_precision_n_width(printf, i);
	if (i < 0 || ((*printf)->plus &&
			*((*printf)->str) != 'u' && *((*printf)->str) != 'U'))
		(*printf)->num++;
	while (i)
	{
		i /= 10;
		(*printf)->num++;
	}
	(*printf)->str += 1;
	(*printf)->i += 1;
}

static void	ft_is_s_or_c(t_printf **printf, va_list argPointer)
{
	char *s;

	if (*((*printf)->str) == 's')
		s = ft_strdup(va_arg(argPointer, char *));
	else if (*((*printf)->str) == 'c')
	{
		if (!(s = (char *)malloc(2)))
			return ;
		s[0] = (unsigned char)va_arg(argPointer, int);
		s[1] = '\0';
	}
	ft_str_precision_n_width(printf, s);
	(*printf)->str += 1;
	(*printf)->i += 1;
//	ft_strdel(&s);
}

static void	zerox(t_printf **printf, va_list argPointer)
{
	char	*string;
	size_t	i;
	char	ch;
	char	*tmp;

	i = 1;
	if (*((*printf)->str) == 'p')
		string = ft_strjoin("0x", ft_itoa_base(va_arg(argPointer,
						unsigned long long), 16));
	else
		string = ft_strjoin("0x", ft_itoa_base(va_arg(argPointer,
						unsigned long), 16));
	ft_p_width(printf, string);
	ft_p_precision(printf, string + 2);
//	ft_strdel(&string);
}

static void	ft_base_hexa(t_printf **printf, va_list argPointer)
{
	size_t	i;
	char	*string;

	i = 0;
	if ((unsigned char)*((*printf)->str) != 'p' && !(*printf)->sharp)
	{
		string = ft_itoa_base(va_arg(argPointer, unsigned long), 16);
		while (*((*printf)->str) == 'X' && string[i++])
			string[i - 1] = ft_toupper(string[i - 1]);
		ft_xo_precision_n_width(printf, string);
	}
	else
		zerox(printf, argPointer);
	(*printf)->str += 1;
	(*printf)->i += 1;
//	ft_strdel(&string);
}

void	ft_what_is_love(t_printf **printf, va_list argPointer)
{
	 if (*((*printf)->str) == 'd' || *((*printf)->str) == 'i' ||
			*((*printf)->str) == 'D' || *((*printf)->str) == 'u' ||
				*((*printf)->str) == 'U')
		ft_isdecimal(printf, argPointer);
	else if (*((*printf)->str) == 's' || *((*printf)->str) == 'c')
		ft_is_s_or_c(printf, argPointer);
	else if (*((*printf)->str) == 'C' || *((*printf)->str) == 'S')
		ft_is_unicode(printf, argPointer);
	else if (*((*printf)->str) == 'x'
			|| *((*printf)->str) == 'X' || *((*printf)->str) == 'p')
		ft_base_hexa(printf, argPointer);
	else if (*((*printf)->str) == 'o' || *((*printf)->str) == 'O')
		ft_base_octo(printf, argPointer);
}
