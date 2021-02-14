#include "ft_printf.h"

void ft_print_nbr(va_list ap, t_var *opt)
{
	int d;
	char *nbr;
	char *nbr2;

	if (opt->start)
		opt->len = va_arg(ap, int);
	d = va_arg(ap, int);
	nbr = ft_itoa(d);
	if (nbr)
	{
		if (opt->dot)
			opt->fill = '0';
		ft_fill_and_print(nbr, opt);
		free(nbr);
	}
}

void ft_print_unsig(va_list ap, t_var *opt)
{
	
}

void ft_print_hex(va_list ap, t_var *opt)
{
	
}
