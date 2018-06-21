/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:25:16 by aroi              #+#    #+#             */
/*   Updated: 2018/06/21 17:26:06 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*itoc(unsigned long long n, int base, int qnt)
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

char		*ft_litoa_base(unsigned long long n, int base)
{
	unsigned long long k;
	int qnt;

	if (base == 10)
		return (ft_litoa(n));
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
