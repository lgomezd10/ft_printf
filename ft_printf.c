#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

//cspdiuxX % x y X conversion hexadecimal sin signo
const char *ft_print_variable(const char *str, va_list ap, t_var *opt)
{
	int d;
	char c;

	if (*str == 'c')
		ft_print_char(ap, opt);
	if (*str == 's')
		ft_print_str(ap, opt);
	if (*str == 'p')
		ft_print_pointer(ap, opt);
	if (*str == 'd' || *str == 'i')
		ft_print_nbr(ap, opt);
	if (*str == 'u')
		ft_print_unsig(ap, opt);
	if (*str == 'x' || *str == 'X')
		ft_print_hex(ap, opt);
	if (*str == '%')
		ft_putchar_fd(*str, 1);
	return ((str + 1));	
}

const char *ft_get_flags(t_var *opt, const char *str)
{
	int i;

	i = 0;
	opt->fill = ' ';
	opt->len = 0;
	opt->right = 1;
	opt->start = 0;
	while (str[i] == '-' || str[i] == '.' || str[i] == '0' || str[i] == '*')
	{
		if (str[i] == '-')
			opt->right = 0;
		if (str[i] == '.')
			opt->dot = 1;
		if (str[i] == '0')
			opt->fill = '0';
		if (str[i] == '*')
			opt->start = '1';
		i++;
	}
	if (ft_isdigit(str[i]))
	{
		opt->len = ft_atoi(&str[i]);
	}
	while (ft_isdigit(str[i]))
		i++;
	return (&str[i]);
}

// ’-0.*’
int ft_printf(const char *format, ...)
{
	va_list ap;
	int i;
	t_var opt;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			format = ft_get_flags(&opt, &format[i]);
			format = ft_print_variable(format, ap, &opt);
			i = 0;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (0);
}
