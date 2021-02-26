#include "ft_double.h"
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
		str_exp = (char *)ft_calloc(sizeof(char), 5);
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
	int		plus;
	
	plus = (!data->nbr && data->fnbr) ? 1 : 0;
	if ((data->str_deci = (char *)ft_calloc(sizeof(char), opt->deci + 6)))
	{
		i = 0;
		if (opt->deci > 0 || opt->hash)
			data->str_deci[i] = '.';
		i++;
		while (i <= opt->deci)
		{
			data->fnbr *= 10.0;
			digit = data->fnbr;
			plus = (plus && digit > 0) ? 0 : plus;
			opt->deci = (data->cut && plus) ? opt->deci + 1 : opt->deci;
			data->fnbr -= digit;
			data->str_deci[i++] = digit + '0';
            //printf("NBR: %d, float: %.20Lf\n", digit, data->fnbr);

		}
		if (data->fnbr >= 0.5)
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

char	*ft_join(t_double *data, t_var *opt)
{
	char *temp;
	
	
	data->str_nbr = ft_llitoa(data->nbr);
	ft_clear_zeros(data, opt);
	if (data->str_nbr && data->str_deci)
		temp = ft_strjoin(data->str_nbr, data->str_deci);
	if (data->str_deci)
		free(data->str_deci);
	if (data->str_nbr)
		free(data->str_nbr);
	data->str_nbr = temp;
	return (temp);
}