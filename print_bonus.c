/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:33 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/24 09:02:35 by user42           ###   ########.fr       */
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

