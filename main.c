#include <stdarg.h>

int		ft_count_qnt(char *str)
{
	int i;
	int qnt;

	i = -1;
	qnt = 0;
	if (str)
		while (str[++i + 1])
			if (str[i] == '%' && str[i + 1] != '%')
				qnt++;
	return (qnt);
}

void	ft_printf(char *str, ...)
{
	va_list argPointer;
	int qnt;

	qnt = ft_count_qnt(str);
	va_start(argPointer, qnt);
	while ()
	va_end(argPointer);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		printf("printf:    ");
		printf(argv[i]);
		printf("ft_printf: ");
		ft_printf(argv[i]);
	}
}
