/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:08:50 by aroi              #+#    #+#             */
/*   Updated: 2018/07/06 22:12:28 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdio.h>
#include <locale.h>

int		main(int argc, char **argv)
{
	setlocale(LC_ALL, "");
	int	p;
	int i;
	int	str[10];
	int str2[3];
	int c1 = L'Ǽ';
	int c2 = L'💩';
	int c3 = L'🌚';

	i = 0;
	str[0] = c1;
	str[1] = c2;
	str[2] = c3;
	str[3] = c1;
	str[4] = c2;
	str[5] = c3;
	str[6] = c3;
	str[7] = c2;
	str[8] = c2;
	str[9] = 0;
	str2[0] = c1;
	str2[1] = c1;
	str2[2] = 0;
	if (argc > 1)
	{


		// write(1, "=================================", 33);
		// write(1, "=================================", 33);
		// write(1, "==============\n", 15);
		// write(1, "                                  CONVERSION\n", 45);
		// write(1, "=================================", 33);
		// write(1, "=================================", 33);
		// write(1, "==============\n", 15);
		// write(1, "ft_printf: ", 11);
		// p = ft_printf("\n| %3.2c | %3.i | %3D | %15u | %.15U | %5.4s | %%\n| %10.9o | %10.9O | %10.9x | %10.9X | %0C | %20.16p\n| %15S\n", 'a', 10, -1, -1, -1, argv[1], -64, -1, -16, 111111, c1, str, str);
		// printf("p: %d\n\nprintf:    ", p);
		// p = printf("\n| %3.2c | %3.i | %3D | %15u | %.15U | %5.4s | %%\n| %10.9o | %10.9O | %10.9x | %10.9X | %0C | %20.16p\n| %15S\n", 'a', 10, -1, -1, -1, argv[1], -64, - 1, -16, 111111, c1, str, str);
		// printf("p: %d\n\n", p);



		// write(1, "=================================", 33);
		// write(1, "=================================", 33);
		// write(1, "==============\n", 15);
		// write(1, "                                ALTERNATE FLAGS\n", 48);
		// write(1, "=================================", 33);
		// write(1, "=================================", 33);
		// write(1, "==============\n", 15);



		// write(1, "ft_printf: ", 11);
		// p = ft_printf("#: %#10.9o | %#10.9O | %#20.13x | %#20.13X\n0: %07i\n", -1, -8, -1, -1, 2);
		// printf("p: %d\nprintf:    ", p);
		// p = printf("#: %#10.9o | %#10.9O | %#20.13x | %#20.13X\n0: %07i\n", -1, -8, -1, -1, 2);
		// printf("p: %d\n", p);

		// write(1, "ft_printf: ", 11);
		// p = ft_printf("0: %07i | %05x | %05s | %03c\n", 10, 2, argv[1], 'c');
		// printf("p: %d\nprintf:    ", p);
		// p = printf("0: %07i | %05x | %05s | %03c\n", 10, 2, argv[1], 'c');
		// printf("p: %d\n", p);

		// write(1, "ft_printf: ", 11);
		// p = ft_printf("space: % i | % u | % o | % x | % s | % c | % p\n", -1, 255, 322, -2, argv[1], 'c', str);
		// printf("p: %d\nprintf:    ", p);
		// p = printf("space: % i | % u | % o | % x | % s | % c | % p\n", -1, 255, 322, -2, argv[1], 'c', str);
		// printf("p: %d\n", p);

		// write(1, "ft_printf: ", 11);
		// p = ft_printf("-: %-5i | %-5u | %-5o | %-15x | %-5s | %-5c | %-20p|\n", -1, 255, 322, -2, argv[1], 'c', str);
		// printf("p: %d\nprintf:    ", p);
		// p = printf("-: %-5i | %-5u | %-5o | %-15x | %-5s | %-5c | %-20p|\n", -1, 255, 322, -2, argv[1], 'c', str);
		// printf("p: %d\n", p);

		// write(1, "ft_printf: ", 11);
		// p = ft_printf("+: %+5i | %+5u | %+5o | %+15x | %+5s | %+5c | %+20p\n", 1, 255, 322, -2, argv[1], 'c', str);
		// printf("p: %d\nprintf:    ", p);
		// p = printf("+: %+5i | %+5u | %+5o | %+15x | %+5s | %+5c | %+20p\n", 1, 255, 322, -2, argv[1], 'c', str);
		// printf("p: %d\n", p);


		// write(1, "ft_printf: ", 11);
		// p = ft_printf("- : %- 5i | %- 5u | %- 5o | %- 15x | %- 5s | %- 5c | %- 20p\n", -1, 255, 322, -2, argv[1], 'c', str);
		// printf("p: %d\nprintf:    ", p);
		// p = printf("- : %- 5i | %- 5u | %- 5o | %- 15x | %- 5s | %- 5c | %- 20p\n", -1, 255, 322, -2, argv[1], 'c', str);
		// printf("p: %d\n", p);
		
//		ft_printf("%o\n", 27);
//		printf("%#a5.7o\n", 27);
//		ft_printf("%5C\n", c3);
//		printf("printf:    %5C\n", c3);
//		ft_printf("%25S\n", str);
//		printf("%25S\n\n", str);
//		ft_printf("%7S\n", str2);
//		printf("%7S\n", str2);
/*
		write(1, "=================================", 33);
		write(1, "=================================", 33);
		write(1, "==============\n", 15);
		write(1, "                                      CAST\n", 43);
		write(1, "=================================", 33);
		write(1, "=================================", 33);
		write(1, "==============\n", 15);
		write(1, "ft_printf: ", 11);
		p = ft_printf("%10.8ld\n", -2147483648);
		printf("p: %d\nprintf:    ", p);
		p = printf("%10.8ld\n", -21474836490);
		printf("p: %d\n", p);
*/
		// ft_printf("|%%|\n");
		// printf("|%%|\n");
		// write(1, "ft_printf: ", 11);
		// p = ft_printf("|%10.12x| |%10.12X|\n", 10, 10);
		// printf("p: %d\nprintf:    ", p);
		// p = printf("|%10.12x| |%10.12X|\n", 10, 10);
		// printf("p: %d\n", p);
		// write(1, "ft_printf: ", 11);
		// p = ft_printf("%s%s%s%s%s\n", "This ", "is ", "a ", "multi ", "string!");
		// printf("p: %d\nprintf:    ", p);
		// p = printf("%s%s%s%s%s\n", "This ", "is ", "a ", "multi ", "string!");
		// printf("p: %d\n", p);

		// write(1, "ft_printf: ", 11);
		// p = ft_printf("|%zhd|\n", 4294967296);
		// printf("p: %d\nprintf:    ", p);
		// p = printf("|%zhd|\n", 4294967296);
		// printf("p: %d\n", p);

	// write(1, "ft_printf: ", 11);
	// p = ft_printf("%4.3S", L"Jambon");
	// printf("p: %d\nprintf:    ", p);
	// p = printf("%4.3S", L"Jambon");
	// printf("p: %d\n", p);

// 		ft_printf("{xuesosredAnton}LOL{eoc} {grey}KEK{eoc} {blue}drug{eoc} {green}ty{eoc} {lightblue}pidor{eoc} \
// {lightgreen}ili{eoc} {yellow}xuylo?{eoc} {purple}A?{eoc} {pink}A?{eoc} {lightblue}A?{eoc} \
// {black}|%5.4d|{eoc}\n", 24);

	ft_printf("{%10.*d}\n", -5, 42);
	printf("{%10.*d}\n", -5, 42);

	// ft_printf("%");
	// printf("%");
	}
	return (0);
}