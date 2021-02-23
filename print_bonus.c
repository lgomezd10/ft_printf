/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:33 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/23 12:40:00 by user42           ###   ########.fr       */
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

char *ft_format_decimal(char *str, t_var *opt)
{
	char *deci;
	int len;
	int cpy;

	len = ft_strlen(str);
	cpy = (len > opt->deci) ? opt->deci : len;
	deci = ft_calloc(sizeof(char), opt->deci + 2);
	ft_memset(deci, '0', opt->deci + 1);
	*deci = '.';
	ft_memcpy((deci + 1), str, cpy);
	if (len > opt->deci && str[opt->deci] > 4 + '0')
		deci[opt->deci]++;
	return (deci);
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

	max = 17;
	nbr = f;
	str_nbr = ft_llitoa(nbr);
    len = ft_strlen(str_nbr);
	if (f < 0)
	{
		f *= -1;
		nbr *= -1;
	}
	f -= nbr;
	nbr_deci = f * (get_mult(max - len));
	str_deci = ft_llitoa(nbr_deci);
	temp = ft_format_decimal(str_deci, opt);
	free(str_deci);
	str_deci = temp;
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