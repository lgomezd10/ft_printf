/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:25:49 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/03/02 19:21:58 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

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
		}
		if ((data->fnbr >= 0.5 && (data->nbr % 2)) || data->fnbr > 0.5)
			ft_add_one(data);
	}
}

void	ft_clear_zeros(t_double *data, t_var *opt)
{
	int i;
	int len;

	i = 0;
	if (data->cut && !(opt->hash && opt->deci))
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

	data->str_nbr = ft_ultoa(data->nbr);
	ft_clear_zeros(data, opt);
	if (data->str_nbr && data->str_deci)
		temp = ft_strjoin(data->str_nbr, data->str_deci);
	if (data->str_deci)
	{
		free(data->str_deci);
		data->str_deci = 0;
	}
	if (data->str_nbr)
		free(data->str_nbr);
	data->str_nbr = temp;
	return (temp);
}
