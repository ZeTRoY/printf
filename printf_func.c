/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:59:58 by aroi              #+#    #+#             */
/*   Updated: 2018/06/12 17:31:22 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_printf	new_printf(void)
{
	t_printf *printf;

	printf = (t_printf *)malloc(sizeof(t_printf));
	if (!printf)
		return (0);
	printf->flag = 0;
	printf->size_flag = 0;
	printf->conv = 0;
	printf->num = 0;
	printf->i = 0;
	return (printf);
}
