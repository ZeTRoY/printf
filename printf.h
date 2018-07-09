/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:14:01 by aroi              #+#    #+#             */
/*   Updated: 2018/07/09 15:23:13 by aroi             ###   ########.fr       */
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

# define YEAR 1000
# define MONTH 12
# define DAY 30

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
	char			cast;
	char			conv;
	int				sigil;
	int				width;
	int				precision;
	int				num;
	int				i;
	char			*str;
	int				fd;
}					t_printf;

typedef struct		s_date
{
	int				year;
	int				month;
	int				day;
	int				hour;
	int				min;
	int				sec;
	int				n;
}					t_date;

int					ft_printf(char *str, ...);

t_printf			*new_printf(void);
void				ft_printf_update(t_printf **printf);
void				ft_del_printf(t_printf **printf);

t_date				*ft_new_date(void);
void				ft_del_date(t_date **date);
void				print_date(t_printf **printf, int date, int specify);

int					is_flag(char *str);
int					is_width(char *str);
int					is_precision(char *str);
int					is_cast(char *str);
int					is_conversion(char *str, int i);
void				ft_flag_activation(t_printf **printf);
void				ft_width_activation(t_printf **printf);
void				ft_precision_activation(t_printf **printf);
void				ft_cast_activation(t_printf **printf);
void				ft_what_is_love(t_printf **printf, va_list apointer);
void				ft_is_decimal(t_printf **printf, va_list apointer);
void				ft_is_unsigned(t_printf **printf, va_list apointer);
void				ft_is_char(t_printf **printf, va_list apointer);
void				ft_is_string(t_printf **printf, va_list apointer);
void				ft_is_bin_dec(t_printf **printf, va_list apointer);
void				ft_is_bin(t_printf **printf, va_list apointer);
void				ft_is_octo(t_printf **printf, va_list apointer);
void				ft_is_hexa(t_printf **printf, va_list apointer);
void				ft_is_base(t_printf **printf, va_list apointer);
void				ft_is_date(t_printf **printf, va_list apointer);
void				ft_print_width(t_printf **print, int qnt);
void				ft_char_precision_n_width(t_printf **printf, char c);
void				ft_p_precision(t_printf **printf, char *str,
						uintmax_t z, int qnt);
int					ft_p_width(t_printf **printf, char *str, uintmax_t z);
void				ft_print_width_x(t_printf **printf, int qnt);
char				size_of(wchar_t c);
int					size_of_str(char *str);
int					size_of_uni_str(wchar_t *str);

int					ft_count_digits_base(intmax_t i, int base);
int					ft_count_udigits_base(uintmax_t n, int base);
int					ft_count_letters(char *str);
intmax_t			ft_pow(intmax_t n, int base);
int					ft_isdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_upper(char **str);
void				ft_putchar(wchar_t c);
void				ft_putstr(char const *s);
void				ft_putnbr(intmax_t n);
int					ft_atoi(const char *str);
char				*ft_itoa(intmax_t n);
char				*ft_uitoa(uintmax_t n);
char				*ft_itoa_base(intmax_t n, int base);
char				*ft_uitoa_base(uintmax_t n, int base);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *str);
char				*ft_strstr(const char *big, const char *little);
void				ft_strdel(char **str);
char				*ft_strjoin(char const *str1, char const *str2);

int					is_sigil(char *str);
void				ft_is_sigil(t_printf **printf);
void				ft_print_number(int qnt, char *str);

int					ft_sqrt(uintmax_t n);
void				ft_is_sqrt(t_printf **printf, va_list apointer);
#endif
