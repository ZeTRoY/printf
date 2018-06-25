/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 09:06:56 by aroi              #+#    #+#             */
/*   Updated: 2018/06/23 20:06:09 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_itoa(intmax_t n)
{
	char	*str;
	int		i;

	str = 0;
	i = ft_count_digits(n);
	if (!(str = (char *)malloc(i + 1)))
		return (str);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[i] = '\0';
	while (i-- > 0)
	{
		if (n < 0)
			str[i] = -(n % 10) + '0';
		else if (n > 0)
			str[i] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
