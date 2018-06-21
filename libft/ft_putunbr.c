/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 10:13:00 by aroi              #+#    #+#             */
/*   Updated: 2018/06/19 17:37:43 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	qnt_counter(unsigned int n)
{
	int qnt;

	qnt = 0;
	while (n)
	{
		n /= 10;
		qnt++;
	}
	return (qnt);
}

void		ft_putunbr(unsigned int n)
{
	int	i;
	int	nbr[qnt_counter(n)];

	i = 0;
	if (n == 0)
		ft_putchar('0');
	while (n)
	{
		nbr[i++] = n % 10;
		n /= 10;
	}
	while (--i >= 0)
		ft_putchar((char)nbr[i] + 48);
}
