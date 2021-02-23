/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:33 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/23 20:03:19 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void ft_save_len(va_list ap, t_var *opt)
{
    int *len;

    len = va_arg(ap, int *);
    *len = opt->out;
}

static char	*ft_load_str(char *str, size_t size, long long int n)
{
	unsigned long long int nbr;

	if (n < 0)
		str[0] = '-';
	nbr = (n < 0) ? n * -1 : n;
	size--;
	str[size] = '\0';
	while (nbr / 10 != 0)
	{
		str[--size] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	str[size - 1] = (nbr % 10) + '0';
	return (str);
}

char		*ft_llitoa(long long int n)
{
	size_t          i;
	size_t			size;
	unsigned long long int 	nbr;
	char			*str;

	i = 1;
	nbr = (n < 0) ? n * -1 : n;
	while (nbr / 10 != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	size = (n < 0) ? i + 2 : i + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (str)
		str = ft_load_str(str, size, n);
	return (str);
}

long long int get_mult(int len)
{
	long long int result;

	result = 1;
	while (len-- > 0)
		result *= 10;
	return result;
}

char *ft_get_decimal(double f, double origin, t_var *opt)
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
			{
				while (str[i] == '9' && i > 0)
					str[i--] = '0';
				if (i != 0)
					str[i]++;
			}			
		}
	}
	return (str);
}

char	*ft_ftoa(double f, t_var *opt)
{
	t_ullint nbr;
	t_ullint nbr_deci;
	int max;
    char *str_nbr;
    char *str_deci;
	char *temp;
    int len;

	max = 9;
	nbr = f;
	str_nbr = ft_llitoa(nbr);
    len = ft_strlen(str_nbr);
	if (f < 0)
	{
		f *= -1;
		nbr *= -1;
	}
	f -= nbr;
	str_deci = ft_get_decimal(f, opt);
	temp = ft_strjoin(str_nbr, str_deci);
	free(str_deci);
	free(str_nbr);
	return (temp);
}

void ft_print_float(va_list ap, t_var *opt)
{
    double number;
	char *str;
	char *temp;
	char *before;

	before = 0;
    number = va_arg(ap, double);
	before = (number < 0) ? ft_load_before(opt, number < 0) : 0;
	if (!opt->dot)
		opt->deci = 6;
    str = (opt->fill == '0' && number < 0) ? ft_ftoa((-1) * number, opt) : ft_ftoa(number, opt);
	if (opt->fill == '0' && number < 0)
	{
		ft_putstr_fd(before, 1);
		opt->len--;
		opt->out++;
	}
	ft_fill_and_print(str, opt);
	if (before)
		free(before);
}