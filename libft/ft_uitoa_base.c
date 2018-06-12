/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:25:16 by aroi              #+#    #+#             */
/*   Updated: 2018/06/10 13:24:29 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoc(unsigned int n, int base, int qnt)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (qnt + 1));
	if (str == 0)
		return (0);
	str[qnt] = '\0';
	while (--qnt >= 0)
	{
		if (n % base < 10)
			str[qnt] = n % base + 48;
		else
			str[qnt] = n % base + 87;
		n /= base;
	}
	return (str);
}

char		*ft_uitoa_base(unsigned int n, int base)
{
	unsigned int k;
	int qnt;

	if (base == 10)
		return (ft_uitoa(n));
	k = n;
	qnt = 0;
	if (k == 0)
		qnt = 1;
	else
		while (k != 0)
		{
			qnt++;
			k /= base;
		}
	return (itoc(n, base, qnt));
}
