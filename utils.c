/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:12:05 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/24 09:59:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_fill_and_print(char *str, t_var *opt)
{
	int len;
	int rest;
	int i;
   
	if (str)
	{
		len = ft_strlen(str);
		rest = (len < opt->len) ? (opt->len - len) : 0;
		opt->out += len + rest;
		if (!opt->right)
			ft_putstr_fd(str, 1);
		i = 0;
		while (i++ < rest)
			ft_putchar_fd(opt->fill, 1);
		if (opt->right)
			ft_putstr_fd(str, 1);
	}
}

char	ft_get_char(unsigned int nbr, int upper)
{
	char c;
	if (nbr < 10)
		c = nbr + '0';
	else
	{
		if (upper)
			c = (nbr - 10) + 'A';
		else
			c = (nbr - 10) + 'a';
	}
	return (c);
}

char	*ft_to_hex(unsigned long long int nbr, int upper)
{
	unsigned long long int div;
	int i;
	char *str;

	div = 1;
	i = 1;
	while (nbr / div > 15)
	{
		div *= 16;
		i++;
	}
	str = (char *)ft_calloc(sizeof(char), i + 1);
	if (str)
	{
		i = 0;
		while (div > 0)
		{
			str[i++] = ft_get_char(nbr / div, upper);
			nbr = nbr % div;
			div = div / 16;
		}
	}
	return (str);
}

char	*ft_pointer_str(unsigned long nbr, int upper)
{
	unsigned long div;
	int i;
	char *str;

	div = 1;
	i = 1;
	while (nbr / div > 15)
	{
		div *= 16;
		i++;
	}
	str = (char *)ft_calloc(sizeof(char), i + 1);
	if (str)
	{
		i = 0;
		while (div > 0)
		{
			str[i++] = ft_get_char(nbr / div, upper);
			nbr = nbr % div;
			div = div / 16;
		}
	}
	return (str);
}

char	*ft_ultoa(unsigned long int nbr)
{
	long int div;
	int i;
	char *str;

	div = 1;
	i = 1;
	while (nbr / div > 9)
	{
		div *= 10;
		i++;
	}
	if ((str = (char *)ft_calloc(sizeof(char), i + 1)))
	{
		i = 0;
		while (div > 0)
		{
			str[i++] = (nbr / div) + '0';
			nbr = nbr % div;
			div = div / 10;
		}
	}
	return (str);
}

void ft_print_data(char **str, t_var *opt)
{
	int len;

	if (str && *str)
	{
		len = ft_strlen(*str);
		ft_putstr_fd(*str, 1);
		opt->len -= len;
		opt->out += len;
		free(*str);
		*str = 0;
	}
}