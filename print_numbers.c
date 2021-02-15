#include "ft_printf.h"
#include <stdio.h>

void ft_print_nbr(va_list ap, t_var *opt)
{
	int d;
	char *nbr;
	char *nbr2;

	if (opt->start)
		opt->len = va_arg(ap, int);
	d = va_arg(ap, int);
	if (opt->dot)
		opt->fill = '0';
	if (opt->fill == '0')
		opt->right = 1;
	if (d < 0 && opt->fill == '0')
	{
		ft_putchar_fd('-', 1);
		opt->out++;
		d *= -1;
	}
	nbr = ft_itoa(d);
	if (nbr)
	{
		ft_fill_and_print(nbr, opt);
		free(nbr);
	}
}

void ft_print_unsig(va_list ap, t_var *opt)
{
	int d;
	unsigned int ud;
	char *nbr;
	char *nbr2;

	if (opt->start)
		opt->len = va_arg(ap, int);
	ud = va_arg(ap, unsigned int);
	if (opt->dot)
		opt->fill = '0';
	if (opt->fill == '0')
		opt->right = 1;
	nbr = ft_utoa(ud);
	if (nbr)
	{
		ft_fill_and_print(nbr, opt);
		free(nbr);
	}
}

void ft_print_hex(va_list ap, t_var *opt, int upper)
{
	unsigned int nbr;
	char *str;

	if (opt->start)
		opt->len = va_arg(ap, int);
	nbr = va_arg(ap, unsigned int);
	str = ft_to_hex(nbr, upper);
	if (str)
	{
		if (opt->dot)
			opt->fill = '0';
		if (opt->fill == '0')
			opt->right = 1;
		ft_fill_and_print(str, opt);
		free(str);
	}
}
