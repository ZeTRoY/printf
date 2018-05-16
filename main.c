#include <stdarg.h>
#include <stdio.h>

int		ft_count_qnt(char *str)
{
	int i;
	int qnt;

	i = -1;
	qnt = 0;
	if (str)
		while (str[++i])
			if (str[i] == '%' && str[i + 1] = '%' &&
		str[i - 1] != '%' && str[i + 1])
				qnt++;
	return (qnt);
}

void	ft_whatisit(char *tmp, char c)
{
	int i;

	i = 0;
	if (*(tmp + 1) == c)
		/*
		*/
}

int		ft_printf(char *str, ...)
{
	int i;
	char c;
	char *tmp;
	va_list argPointer;
	int qnt;
	
	i = 0;
	qnt = ft_count_qnt(str);
	va_start(argPointer, qnt);
	while (qnt-- > 0)
	{
		tmp = ft_strchr(str, '%');
		c = va_arg(argPointer, char);
		ft_whatisit(tmp, c);
		if (*(tmp + 1) == '%')
			str = tmp + 2;
		else
			str = tmp + 1;
	}
	ft_putstr(tmp);
	va_end(argPointer);
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		printf("printf:    \n");
//		printf(argv);
		printf("ft_printf: \n");
//		ft_printf(argv);
	}
	return (0);
}
