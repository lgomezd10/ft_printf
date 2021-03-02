/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:31:16 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/03/02 20:18:46 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

void	ft_add_one(t_double *data)
{
	int len;

	len = ft_strlen(data->str_deci);
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

int		ft_get_exp(t_double *data)
{
	data->fnbr_exp = data->fnbr;
	data->exp = 0;
	if (data->fnbr_exp)
	{
		if (data->fnbr_exp >= 10.0)
		{
			while (data->fnbr_exp >= 10 && data->exp <= 308)
			{
				data->exp++;
				data->fnbr_exp = data->fnbr_exp / 10;
			}
		}
		else if (data->fnbr_exp < 1.0)
		{
			while (data->fnbr_exp < 1.0)
			{
				data->exp--;
				data->fnbr_exp = data->fnbr_exp * 10;
			}
		}
	}
	return (data->exp);
}

void	ft_copy_exp(char *dest, char *src, int isneg, int len)
{
	if (isneg)
		ft_memcpy(dest, "e-", 2);
	else
		ft_memcpy(dest, "e+", 2);
	dest[2] = '0';
	if (len > 1)
		ft_memcpy(&dest[2], src, len);
	else
		ft_memcpy(&dest[3], src, len);
}

void	ft_add_exp(char **str, int exp)
{
	char	*str_exp;
	char	*temp;
	int		len;
	int		isneg;

	isneg = (exp < 0) ? 1 : 0;
	exp = (exp < 0) ? exp * -1 : exp;
	if (str && *str && (temp = ft_itoa(exp)))
	{
		len = ft_strlen(temp);
		if ((str_exp = (char *)ft_calloc(sizeof(char), len + 4)))
		{
			ft_copy_exp(str_exp, temp, isneg, len);
			free(temp);
			if ((temp = ft_strjoin(*str, str_exp)))
			{
				free(*str);
				*str = temp;
			}
			free(str_exp);
		}
		else
			free(temp);
	}
}
