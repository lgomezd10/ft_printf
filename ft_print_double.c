#include "ft_printf.h"
#include <stdio.h>

void	ft_add_one(t_double *data)
{
	int len;
	int i;

	len = ft_strlen(data->str_deci);
	i = len;
	if (!len)
		data->nbr++;
	else
	{
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
	int		end;
	int		plus;

	end = ((int)data->fnbr == 0) ? -1 : 0;
	plus = (!data->nbr && data->fnbr) ? 1 : 0;
	if ((data->str_deci = ft_calloc(sizeof(char), 20)))
	{
		i = 0;
		if (opt->deci > 0 || opt->hash)
			data->str_deci[i] = '.';
		i++;
		while (i <= opt->deci)
		{
			data->fnbr *= 10.0;
			digit = data->fnbr;
			end = (digit > 0) ? 0 : end;
			opt->deci = (data->cut && plus && end < 0) ? opt->deci + 1 : opt->deci;
			end = (end == 0 && data->cut && digit == 0) ? 1 : end;
			data->fnbr -= digit;
			data->str_deci[i++] = digit + '0';

		}
		//if (/*!(data->fnbr <= 0.5 && data->fnbr > 0.4999999) && */data->fnbr > 0.499)
		if (data->fnbr > 0.499)
			ft_add_one(data);
	}
}

void	ft_clear_zeros(t_double *data, t_var *opt)
{
	int i;
	int len;

	i = 0;
	if (data->cut)
	{
		if (data->str_deci && (len = ft_strlen(data->str_deci)))
		{
			while (len > 0)
			{
				len--;
				if (data->str_deci[len] == '0')
					data->str_deci[len] = '\0';
				else
					len = 0;
			}
			if (ft_strlen(data->str_deci) == 1 && !opt->hash)
				data->str_deci[0] = '\0';
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
	ft_clear_zeros(data, opt);
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
	ft_clear_zeros(data, opt);
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

char	*ft_gtoa(t_double *data, t_var *opt)
{
	char	*temp;
	int		len;

	temp = 0;
	data->cut = 1;
	data->nbr = data->fnbr;
	opt->deci = (opt->dot) ? opt->deci : 6;
	if ((data->str_nbr = ft_llitoa(data->nbr)))
	{
		len = ft_strlen(data->str_nbr);
		free(data->str_nbr);
		data->str_nbr = 0;
		if (data->fnbr < 0.0001 && data->fnbr && (len > opt->deci || data->fnbr < 0.00009))
		{
			opt->deci--;
			temp = ft_dtoa(data, opt);
		}
		else
		{
			//opt->deci -= len;
			opt->deci = ((int)data->fnbr == 0) ? opt->deci : opt->deci - len;
			temp = ft_ftoa(data, opt);
		}
	}
	return (temp);
}

void	ft_print_double(va_list ap, t_var *opt, char t)
{
	char		*str;
	char		*before;
	t_double	data;

	data.fnbr = va_arg(ap, double);
	data.nbr = 0;
	data.cut = 0;
	data.isneg = (data.fnbr == 0.0) ? (1 / data.fnbr) != (1 / 0.0)
	: data.fnbr < 0;
	opt->fill = (!opt->right && opt->fill == '0') ? ' ' : opt->fill;
	before = ft_load_before(opt, data.isneg);
	if (!opt->dot)
		opt->deci = 6;
	data.fnbr = (data.isneg) ? data.fnbr * -1 : data.fnbr;
	str = (t == 'f') ? ft_ftoa(&data, opt) : 0;
	str = (t == 'e') ? ft_dtoa(&data, opt) : str;
	str = (t == 'g') ? ft_gtoa(&data, opt) : str;
	if (opt->fill != '0' && before && (data.str_deci = ft_strjoin(before, str)))
	{
		free(str);
		str = data.str_deci;
	}
	if (str && before && opt->fill == '0')
		ft_print_data(&before, opt);
	ft_fill_and_print(str, opt);
	if (before)
		free(before);
	if (str)
		free(str);
}
