/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:14:01 by aroi              #+#    #+#             */
/*   Updated: 2018/06/12 17:54:12 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

typedef struct		s_printf
{
	char			flag;
	char			size_flag;
	char			conv;
	int				num;
	int				i;
	char			*str;
}					t_printf;

t_printf			*new_printf(void);
int					is_flag(char **str);
int					is_size_flag(char *str);
int					is_conversion(char *str);
void				ft_flag_activation(t_printf printf);
void				ft_flag_size_activation(t_printf printf);
void				ft_what_is_love(t_printf printf, va_list argPointer);
void				ft_iswchar(t_printf printf, va_list argPointer);	
void				ft_iswint(t_printf printf, va_list argPointer);

#endif
