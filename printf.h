/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:14:01 by aroi              #+#    #+#             */
/*   Updated: 2018/06/21 17:39:18 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

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
int					is_flag(char *str);
int					is_size_flag(char *str);
int					is_conversion(char *str);
void				ft_flag_activation(t_printf **printf);
void				ft_flag_size_activation(t_printf **printf);
void				ft_what_is_love(t_printf **printf, va_list argPointer);
void				ft_iswchar(t_printf *printf, va_list argPointer);	
void				ft_iswint(t_printf *printf, va_list argPointer);
void				ft_is_C_or_S(t_printf **printf, va_list argPointer);

int					ft_toupper(int c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putunbr(unsigned int n);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
char				*ft_uitoa(unsigned int n);
char				*ft_uitoa_base(unsigned int n, int base);
char				*ft_litoa(unsigned long long n);
char				*ft_litoa_base(unsigned long long n, int base);

#endif
