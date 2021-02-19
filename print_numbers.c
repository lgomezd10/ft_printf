/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:58 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/19 10:14:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char *ft_load_digit_nbr(char *before, char *nbr, t_var *opt)
{
	int lnbr;
	int lbefore;
	int lzeros;
	char *new;
	
	new = 0;
	opt->fill = (!opt->right) ? ' ' : opt->fill;
	if (opt->dot || (!opt->dot && opt->fill != '0'))
	{
		lbefore = ft_strlen(before);
		lnbr = ft_strlen(nbr);
		lzeros = (opt->dot && lnbr < opt->decimal) ? opt->decimal - lnbr : 0;
		new = ft_calloc(sizeof(char), lbefore + lnbr + lzeros + 1);
		ft_memset(new, '0', lbefore + lnbr + lzeros);
		ft_memcpy(new, before, ft_strlen(before));
		ft_memcpy(&new[lbefore + lzeros], nbr, lnbr);
		if (opt->dot)
		{
			opt->fill = ' ';
			opt->dot = 0;
		}
	}
	return (new);
}

void ft_print_nbr(va_list ap, t_var *opt)
{
	long int d;
	long int nosigne;
	char *nbr;
	char *temp;

	d = (long int)va_arg(ap, int);
	nosigne = (d < 0) ? d * -1 : d;	
	if ((temp = ft_itoa(nosigne)))
	{
		nbr = (d < 0) ? ft_load_digit_nbr("-", temp, opt) : ft_load_digit_nbr("", temp, opt);
		if (!nbr)
			nbr = temp;
		else
			free(temp);
		if (opt->fill == '0' && d < 0)
		{
			ft_putchar_fd('-', 1);
			opt->len--;
		}
		ft_fill_and_print(nbr, opt);
		free(nbr);
	}	
}

void ft_print_unsig(va_list ap, t_var *opt)
{
	int d;
	unsigned int ud;
	char *nbr;
	char *nbr2;

	ud = va_arg(ap, unsigned int);
	if (opt->dot)
		opt->fill = '0';
	if (opt->fill == '0')
		opt->right = 1;
	nbr = ft_utoa(ud);
	if (nbr)
	{
		ft_fill_and_print(nbr, opt);
		free(nbr);
	}
}

void ft_print_hex(va_list ap, t_var *opt, int upper)
{
	unsigned int nbr;
	char *str;

	nbr = va_arg(ap, unsigned int);
	str = ft_to_hex(nbr, upper);
	if (str)
	{
		if (opt->dot)
			opt->fill = '0';
		if (opt->fill == '0')
			opt->right = 1;
		ft_fill_and_print(str, opt);
		free(str);
	}
}
