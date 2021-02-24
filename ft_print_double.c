#include "ft_printf.h"
#include <stdio.h>

void ft_add_one(char *deci, t_ullint *nbr)
{
	int len;

	len = ft_strlen(deci);
	len--;
	while (len > 1 && deci[len] == '9')
		deci[len--] = '0';
	if (deci[len] == '9')
	{
		deci[len] = '0';
		(*nbr)++;
	}
	else
		deci[len]++;
}

char *ft_get_decimal(double f, t_ullint *nbr, t_var *opt)
{
	int i;
	int digit;
	char *str;

	str = ft_calloc(sizeof(char), opt->deci + 2);
	if (str)
	{
		i = 0;
		str[i++] = '.';
		while (i < opt->deci + 1)
		{
			f *= 10;
			digit = f;
			f -= digit;
			str[i++] = digit + '0';
		}
		if (i > 0)
		{
			i--;
			f *= 10;
			if ((digit = f) > 4)
				ft_add_one(str, nbr);
		}
	}
	return (str);
}

char	*ft_ftoa(double f, t_var *opt)
{
	t_ullint nbr;
	t_ullint nbr_deci;
    char *str_nbr;
    char *str_deci;
	char *temp;

	nbr = f;	
	if (f < 0)
	{
		f *= -1;
		nbr *= -1;
	}
	f -= nbr;
	str_deci = ft_get_decimal(f, &nbr, opt);
	str_nbr = ft_llitoa(nbr);
	temp = ft_strjoin(str_nbr, str_deci);
	free(str_deci);
	free(str_nbr);
	return (temp);
}

void ft_add_exp(char **str, int exp)
{
	char *str_exp;
	char *out;

	if (str && *str)
	{
		str_exp = ft_calloc(sizeof(char), 5);
		if (exp < 0)
		{
			ft_memcpy(str_exp, "e-", 2);
			exp *= -1;
		}
		else
			ft_memcpy(str_exp, "e+", 2);
		str_exp[2] = (exp / 10) + '0';
		str_exp[3] = (exp % 10) + '0';
		out = ft_strjoin(*str, str_exp);
		free(str_exp);
		if (out)
		{
			free(*str);
			*str = out;
		}		
	}
}

void *ft_dtoa(double f, t_var *opt)
{
    t_ullint nbr;
	t_ullint nbr_deci;
    int exp;
    char *str_nbr;
    char *str_deci;
    char *temp;

    nbr = f;
    exp = 0;
	while (nbr > 9)
	{
		exp++;
		f = f / 10;
		nbr = f;
	}
	while (nbr == 0)
	{
		exp--;
		f = f * 10;
		nbr = f;
	}
		
    f -= nbr;
    str_deci = ft_get_decimal(f, &nbr, opt);
	str_nbr = ft_llitoa(nbr);
	temp = ft_strjoin(str_nbr, str_deci);
	ft_add_exp(&temp, exp);
	free(str_deci);
	free(str_nbr);
	return (temp);
}

void ft_print_double(va_list ap, t_var *opt, char t)
{
    double  number;
	char    *str;
	char    *before;
    int     isneg;

	number = va_arg(ap, double);
	before = ((isneg = number < 0)) ? ft_load_before(opt, number < 0) : 0;
	if (!opt->dot)
		opt->deci = 6;
    number = (isneg && opt->fill == '0') ? number * -1 : number;
    str = (t == 'f') ? ft_ftoa(number, opt) : 0;
    str = (t == 'e') ? ft_dtoa(number, opt) : str;
    str = (t == 'g') ? ft_dtoa(number, opt) : str;
	if (str && opt->fill == '0' && number < 0)
	{
		ft_putstr_fd(before, 1);
		opt->len--;
		opt->out++;
	}
	ft_fill_and_print(str, opt);
	if (before)
		free(before);
    if (str)
        free(str);
}