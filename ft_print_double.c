#include "ft_printf.h"
#include <stdio.h>

void	ft_add_one(t_double *data)
{
	int len;

	len = ft_strlen(data->str_deci);
	len--;
	while (len > 1 && data->str_deci[len] == '9')
		data->str_deci[len--] = '0';
	if (data->str_deci[len] == '9')
	{
		data->str_deci[len] = '0';
		data->nbr++;
	}
	else
		data->str_deci[len]++;
}

void	ft_add_exp(char **str, int exp)
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

void	ft_get_decimal(t_double *data, t_var *opt)
{
	int		i;
	int		digit;

	data->str_deci = 0;
	if ((data->str_deci = ft_calloc(sizeof(char), opt->deci + 2)))
	{
		i = 0;
		if (opt->deci > 0)
			data->str_deci[i] = '.';
		i++;
		while (i < opt->deci + 1)
		{
			data->fnbr *= 10;
			digit = data->fnbr;
			data->fnbr -= digit;
			data->str_deci[i++] = digit + '0';
		}
		if (i > 0)
		{
			i--;
			data->fnbr *= 10;
			if ((digit = data->fnbr) > 4)
				ft_add_one(data);
		}
	}
}

char	*ft_ftoa(t_double *data, t_var *opt)
{
	char *temp;

	temp = 0;
	data->nbr = data->fnbr;	
	data->fnbr -= data->nbr;
	data->str_deci = 0;
	ft_get_decimal(data, opt);
	data->str_nbr = ft_llitoa(data->nbr);
	if (data->str_nbr && data->str_deci)
		temp = ft_strjoin(data->str_nbr, data->str_deci);
	if (data->str_deci)
		free(data->str_deci);
	if (data->str_nbr)
		free(data->str_nbr);
	return (temp);
}

void	*ft_dtoa(t_double *data, t_var *opt)
{
	int exp;
	char *temp;

	data->nbr = data->fnbr;
	exp = 0;
	temp = 0;
	if (data->fnbr)
	{
		while (data->nbr > 9 || data->nbr == 0)
		{
			exp = (data->nbr == 0) ? exp - 1 : exp + 1;
			data->fnbr = (data->nbr == 0) ? data->fnbr * 10 : data->fnbr / 10;
			data->nbr = data->fnbr;
		}
	}
	data->fnbr -= data->nbr;
	data->str_nbr = 0;
	ft_get_decimal(data, opt);
	data->str_nbr = ft_llitoa(data->nbr);
	if (data->str_nbr && data->str_deci)
		temp = ft_strjoin(data->str_nbr, data->str_deci);
	ft_add_exp(&temp, exp);
	if (data->str_deci)
		free(data->str_deci);
	if (data->str_nbr)
		free(data->str_nbr);
	data->str_nbr = temp;
	return (temp);
}

void	ft_print_double(va_list ap, t_var *opt, char t)
{
	char		*str;
	char		*before;
	t_double	data;

	data.fnbr = va_arg(ap, double);
	data.nbr = 0;
	data.isneg = (data.fnbr == 0.0) ? (1 / data.fnbr) != (1 / 0.0)
	: data.fnbr < 0;
	before = ft_load_before(opt, data.isneg);
	if (!opt->dot)
		opt->deci = 6;
	data.fnbr = (data.isneg) ? data.fnbr * -1 : data.fnbr;
	str = (t == 'f') ? ft_ftoa(&data, opt) : 0;
	str = (t == 'e') ? ft_dtoa(&data, opt) : str;
	str = (t == 'g') ? ft_dtoa(&data, opt) : str;
	if (opt->fill != '0' && before && (data.str_deci = ft_strjoin(before, str)))
	{
		free(str);
		str = data.str_deci;
	}
	if (str && opt->fill == '0' && data.isneg)
		ft_print_data(&before, opt);
	ft_fill_and_print(str, opt);
	if (before)
		free(before);
	if (str)
		free(str);
}
