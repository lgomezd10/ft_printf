#include "ft_printf.h"

void ft_check_flags(char *str)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	if (str[i] != '0' && ft_isdigit(str[i]))
	{
		nbr = ft_atoi(str[i]);
	}
}

int printf(const char *format, ...)
{
	va_list ap;
	int i;

	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_check_flags(format[i + 1]);
		}
		else
		ft_putchar_fd(format[i], 1);
		i++;
	}
	
}
