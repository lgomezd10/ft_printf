#include "ft_printf.h"
#include "libft/libft.h"

void ft_check_flags(char *str)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	if (str[i] != '0' && ft_isdigit(str[i]))
	{
		nbr = ft_atoi(&str[i]);
	}
}
//cspdiuxX % x y X conversion hexadecimal sin signo
const char *ft_print_variable(const char *str, va_list ap)
{
	int d;
	char c;

	switch (*(str + 1))
	{
	case 'c':
		c = (char)va_arg(ap, int);
		ft_putchar_fd(c, 1);
		break;
	case 's':
		break;
	case 'p':
		break;
	case 'd':
	case 'i':
		d = va_arg(ap, int);
		ft_putnbr_fd(d, 1);
		break;
	case 'u':
		break;
	case 'x':
	case 'X':
		break;
	default:
		ft_putchar_fd(*(str + 1), 1);
		ft_putendl_fd(" error", 1);
		break;
	}
	return ((str + 2));	
}

// ’-0.*’
int ft_printf(const char *format, ...)
{
	va_list ap;
	int i;

	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			format = ft_print_variable(&format[i], ap);
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
