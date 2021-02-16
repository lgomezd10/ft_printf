/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:12:05 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/16 15:12:53 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_fill_and_print(char *str, t_var *opt)
{
    int len;
    int i;

    len = ft_strlen(str);
    opt->out += (len < opt->len) ? opt->len : len; 
    len = (len < opt->len) ? (opt->len - len) : 0;
    if (!opt->right)
        ft_putstr_fd(str, 1);
    i = 0;
    while (i++ < len)
        ft_putchar_fd(opt->fill, 1);
    if (opt->right)
        ft_putstr_fd(str, 1);
}

char ft_get_char(unsigned int nbr, int upper)
{
	char c;
	if (nbr < 10)
		c = nbr + '0';
	else
        if (upper)
            c = (nbr - 10) + 'A';
        else
		    c = (nbr - 10) + 'a';
	return (c);
}

char *ft_to_hex(unsigned int nbr, int upper)
{
	int div;
	int i;
	char *str;

	div = 1;
	i = 1;
	while (nbr / div > 15)
	{
		div *= 16;
		i++;
	}
	str = ft_calloc(sizeof(char), i + 1);
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

char *ft_pointer_str(unsigned long nbr, int upper)
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
	str = ft_calloc(sizeof(char), i + 3);
    if (str)
    {
        i = 2;
        ft_memcpy(str, "0x", 2);
        while (div > 0)
        {
            str[i++] = ft_get_char(nbr / div, upper);
            nbr = nbr % div;
            div = div / 16;
        }
    }
    return (str);
}

char		*ft_utoa(unsigned int nbr)
{
	int div;
	int i;
	char *str;

	div = 1;
	i = 1;
	while (nbr / div > 9)
	{
		div *= 10;
		i++;
	}
	str = ft_calloc(sizeof(char), i + 1);
    if (str)
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