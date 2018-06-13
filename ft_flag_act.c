/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_act.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:40:36 by aroi              #+#    #+#             */
/*   Updated: 2018/06/13 15:49:16 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_flag_activation(t_printf **printf)
{
	if ((*printf)->str[0] == '#')
		(*printf)->flag = '#';
	else if ((*printf)->str[0] == '0')
		(*printf)->flag = '0';
	else if ((*printf)->str[0] == '-')
		(*printf)->flag = '-';
	else if ((*printf)->str[0] == '+')
		(*printf)->flag = '+';	
	else
		(*printf)->flag = ' ';
	(*printf)->str++;
	(*printf)->i++;
}
