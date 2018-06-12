/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 09:06:56 by aroi              #+#    #+#             */
/*   Updated: 2018/06/10 13:21:59 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	qnt_counter(unsigned int n)
{
	size_t qnt;

	qnt = 0;
	if (n == 0)
		qnt = 1;
	else
		while (n > 0)
		{
			n /= 10;
			qnt++;
		}
	return (qnt);
}

char			*ft_uitoa(unsigned int n)
{
	int		i;
	int		j;
	int		qnt;
	int		nbr[qnt_counter(n)];
	char	*str;

	qnt = qnt_counter(n);
	str = (char *)malloc(sizeof(char) * (qnt + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (n > 0)
	{
		nbr[j++] = n % 10;
		n /= 10;
	}
	while (j >= 0)
		str[i++] = (char)nbr[--j] + 48;
	str[qnt] = '\0';
	return(str);
}
