#include "ft_double.h"
#include <stdio.h>

char	*ft_ftoa(t_double *data, t_var *opt)
{
	char *temp;
	int exp;

	temp = 0;
	//if (data->fnbr < MAX_SUPPORT)
	//{
		exp = (!data->fnbr_exp) ? ft_get_exp(data) : data->exp;	
		data->nbr = data->fnbr;	
		data->fnbr -= data->nbr;
		data->str_nbr = 0;
		ft_get_decimal(data, opt);
		temp = ft_join(data, opt);
	//}
	//else
		//temp = ft_strdup("inf");
	return (temp);
}

void	*ft_dtoa(t_double *data, t_var *opt)
{
	int exp;
	char *temp;
	int i = 0;

	exp = 0;
	temp = 0;
	exp = (!data->fnbr_exp) ? ft_get_exp(data) : data->exp;
	data->fnbr = data->fnbr_exp;
	data->nbr = data->fnbr;
	data->fnbr -= data->nbr;
	data->str_nbr = 0;
	ft_get_decimal(data, opt);
	if (data->nbr == 10)
	{
		data->nbr = 1;
		exp++;
	}
	temp = ft_join(data, opt);
	ft_add_exp(&temp, exp);
	return (temp);
}

char	*ft_gtoa(t_double *data, t_var *opt)
{
	char	*temp;
	int		len;
	long double count;
	int		exp;

	temp = 0;
	//if (data->fnbr < MAX_SUPPORT)
	//{
		data->cut = 1;
		opt->deci = (opt->dot) ? opt->deci : 6;
		count = data->fnbr;
		exp = ft_get_exp(data);
		len = (exp < 0) ? 1 : exp + 1;
		data->nbr = data->fnbr;	
		if (data->fnbr && ((len > opt->deci && len > 1) || data->fnbr < 0.0001))
		{
			opt->deci--;
			temp = ft_dtoa(data, opt);
		}
		else
		{
			opt->deci = (data->nbr == 0) ? opt->deci : opt->deci - len;
			opt->deci = (!data->nbr && !opt->deci) ? opt->deci + 1 : opt->deci;
			temp = ft_ftoa(data, opt);
		}
	//}
	return (temp);	
}

void	ft_load_data_double(va_list ap, t_double *data, t_var *opt)
{
	data->fnbr = va_arg(ap, double);
	data->fnbr_exp = 0.0;
	data->nbr = 0;
	data->cut = 0;
	data->isneg = (data->fnbr == 0.0) ? (1 / data->fnbr) != (1 / 0.0)
	: data->fnbr < 0;
	opt->fill = (!opt->right && opt->fill == '0') ? ' ' : opt->fill;
	data->str_deci = 0;
	data->str_nbr = 0;
}

void	ft_print_double(va_list ap, t_var *opt, char t)
{
	char		*str;
	char		*before;
	t_double	data;

	ft_load_data_double(ap, &data, opt);
	before = ft_load_before(opt, data.isneg);
	if (!opt->dot)
		opt->deci = 6;
	data.fnbr = (data.isneg) ? data.fnbr * -1 : data.fnbr;
	if (data.fnbr < MAX_SUPPORT)
		{
		str = (t == 'f') ? ft_ftoa(&data, opt) : 0;
		str = (t == 'e') ? ft_dtoa(&data, opt) : str;
		str = (t == 'g') ? ft_gtoa(&data, opt) : str;
		if (str && opt->fill != '0' && before && (data.str_nbr = ft_strjoin(before, str)))
		{
			free(str);
			str = data.str_nbr;
		}
		if (str && before && opt->fill == '0')
			ft_print_data(&before, opt);
		ft_fill_and_print(str, opt);
		if (before)
			free(before);
		if (str)
		{
			free(str);
			data.str_nbr = 0;
		}
	}
	else
		ft_putstr_fd("inf", 1);
	
}
