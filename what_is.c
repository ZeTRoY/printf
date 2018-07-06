/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:29:24 by aroi              #+#    #+#             */
/*   Updated: 2018/07/06 22:02:48 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_flag(char *str)
{
	if (*str == '#' || *str == '0' || *str == '-' || *str == '+' || *str == ' ')
		return (1);
	return (0);
}

int		is_width(char *str)
{
	if ((*str >= '1' && *str <= '9') || *str == 42)
		return (1);
	return (0);
}

int		is_precision(char *str)
{
	if (*str == '.')
		return (1);
	return (0);
}

int		is_cast(char *str)
{
	if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z' || *str == 'L')
		return (1);
	return (0);
}

int		is_conversion(char *str)
{
	if (*str == 's' || *str == 'S' || *str == 'p' || *str == 'd' || *str == 'D'
		|| *str == 'i' || *str == 'o' || *str == 'O' || *str == 'u' ||
		*str == 'U' || *str == 'x' || *str == 'X' || *str == 'c' || *str == 'C')
		return (1);
	return (0);
}
