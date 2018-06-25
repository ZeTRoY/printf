/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:14:01 by aroi              #+#    #+#             */
/*   Updated: 2018/06/24 18:55:24 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define H	1
# define HH	2
# define L	3
# define LL	4
# define J	5
# define Z	6

# define _00000111 7
# define _00001111 15
# define _00011111 31
# define _00111111 63
# define _10000000 128
# define _11000000 192
# define _11100000 224
# define _11110000 240
# define _7_BITS 127
# define _11_BITS 2047
# define _16_BITS 65535

# define LONG 922337203685477580

# include <wchar.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_printf
{
	char			sharp;
	char			zero;
	char			minus;
	char			plus;
	char			space;
	char			apostrophe;
	char			cast;
	int				width;
	int				precision;
	int				num;
	int				i;
	char			*str;
}					t_printf;

int					ft_printf(char *str, ...);

t_printf			*new_printf(void);
void				ft_printf_update(t_printf **printf);
int					is_flag(char *str);
int					is_width(char *str);
int					is_precision(char *str);
int					is_cast(char *str);
int					is_conversion(char *str);
void				ft_flag_activation(t_printf **printf);
void				ft_width_activation(t_printf **printf);
void				ft_precision_activation(t_printf **printf);
void				ft_cast_activation(t_printf **printf);
void				ft_what_is_love(t_printf **printf, va_list argPointer);
void				ft_iswchar(t_printf *printf, va_list argPointer);	
void				ft_iswint(t_printf *printf, va_list argPointer);
void				ft_is_unicode(t_printf **printf, va_list argPointer);
void				ft_base_octo(t_printf **printf, va_list argPointer);
void				ft_print_width(t_printf **print, intmax_t qnt);
void				ft_diu_precision_n_width(t_printf **printf, intmax_t i);
void				ft_xo_precision_n_width(t_printf **printf, char *str);
void				ft_char_precision_n_width(t_printf **printf, char c);
void				ft_str_precision_n_width(t_printf **printf, char *str);
void				ft_p_precision(t_printf **printf, char *str);
void				ft_p_width(t_printf **printf, char *str);
void				ft_C_precision_n_width(t_printf **printf, wchar_t c,
				int size);
void				ft_S_precision_n_width(t_printf **printf, wchar_t *str,
				int size);

int					ft_count_digits(intmax_t i);
int					ft_count_letters(char *str);

intmax_t			di_cast(t_printf **printf, intmax_t d);

int					ft_isdigit(int c);
int					ft_toupper(int c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(intmax_t n);
int					ft_atoi(const char *str);
char				*ft_itoa(intmax_t n);
char				*ft_itoa_base(intmax_t n, int base);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *str);
void				ft_strdel(char **str);
char				*ft_strjoin(char const *str1, char const *str2);

#endif
