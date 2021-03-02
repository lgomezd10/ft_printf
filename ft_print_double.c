/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:55:00 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/03/02 16:08:44 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

char	*ft_ftoa(t_double *data, t_var *opt)
{
	char	*temp;
	int		exp;

	temp = 0;
	exp = (!data->fnbr_exp) ? ft_get_exp(data) : data->exp;
	data->nbr = data->fnbr;
	data->fnbr -= data->nbr;
	data->str_nbr = 0;
	ft_get_decimal(data, opt);
	temp = ft_join(data, opt);
	return (temp);
}

void	*ft_dtoa(t_double *data, t_var *opt)
{
	int		exp;
	char	*temp;

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
	char		*temp;
	int			len;
	long double	count;
	int			exp;

	temp = 0;
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
		opt->deci = (!data->nbr && !opt->deci) ? opt->deci + 1 : opt->deci;
		opt->deci = (!data->nbr && data->fnbr) ? opt->deci : opt->deci - len;
		temp = ft_ftoa(data, opt);
	}
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
	if (!opt->dot)
		opt->deci = 6;
	data->fnbr = (data->isneg) ? data->fnbr * -1 : data->fnbr;
	data->before = ft_load_before(opt, data->isneg);
}

void	ft_print_double(va_list ap, t_var *opt, char t)
{
	char		*str;
	t_double	data;

	ft_load_data_double(ap, &data, opt);
	str = (data.fnbr <= MAX_SUPPORT && t == 'f') ? ft_ftoa(&data, opt) : 0;
	str = (data.fnbr <= MAX_SUPPORT && t == 'e') ? ft_dtoa(&data, opt) : str;
	str = (data.fnbr <= MAX_SUPPORT && t == 'g') ? ft_gtoa(&data, opt) : str;
	str = (data.fnbr > MAX_SUPPORT) ? ft_strdup("inf") : str;
	if (str && opt->fill != '0' && data.before &&
	(data.str_nbr = ft_strjoin(data.before, str)))
	{
		free(str);
		str = data.str_nbr;
	}
	if (str && data.before && opt->fill == '0')
		ft_print_data(&data.before, opt);
	ft_fill_and_print(str, opt);
	if (data.before)
		free(data.before);
	if (str)
	{
		free(str);
		data.str_nbr = 0;
	}
}
