/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:58 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/21 08:46:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_load_digit_nbr(char *before, char *nbr, t_var *opt)
{
	int		lnbr;
	int		lbefore;
	int		lzeros;
	char	*new;

	new = 0;
	opt->fill = (!opt->right || opt->dot) ? ' ' : opt->fill;
	if (opt->dot || (!opt->dot && opt->fill != '0'))
	{
		lbefore = (before) ? ft_strlen(before) : 0;
		lnbr = ft_strlen(nbr);
		while (opt->dot && opt->deci < lnbr && *nbr == '0')
		{
			*nbr++;
			lnbr--;
		}
		lzeros = (opt->dot && lnbr < opt->deci) ? opt->deci - lnbr : 0;
		new = ft_calloc(sizeof(char), lbefore + lnbr + lzeros + 1);
		ft_memset(new, '0', lbefore + lnbr + lzeros);
		if (before)
			ft_memcpy(new, before, lbefore);
		ft_memcpy(&new[lbefore + lzeros], nbr, lnbr);
		opt->dot = 0;
	}
	return (new);
}

void	ft_print_nbr(va_list ap, t_var *opt)
{
	long int	d;
	long int	usig;
	char		*nbr;
	char		*temp;
	char		*before;

	d = (long int)va_arg(ap, int);
	usig = (d < 0) ? d * -1 : d;
	before = (d < 0) ? ft_strdup("-") : 0;
	before = (opt->space && !opt->sign && d >= 0) ? ft_strdup(" ") : before;
	before = (opt->sign && d >= 0) ? ft_strdup("+") : before;
	temp = (d == -2147483648) ? ft_strdup("2147483648") : ft_itoa(usig);
	if (temp)
	{
		if (!(nbr = ft_load_digit_nbr(before, temp, opt)))
			nbr = temp;
		else
			free(temp);
		if (opt->fill == '0' && (d < 0 || opt->sign))
			ft_print_data(&before, opt);
		ft_fill_and_print(nbr, opt);
		free(nbr);
	}
	if (before)
		free(before);
}

void	ft_print_unsig(va_list ap, t_var *opt)
{
	int				d;
	unsigned int	ud;
	char			*str;
	char			*temp;

	ud = va_arg(ap, unsigned int);
	if ((temp = ft_utoa(ud)))
	{
		if (!(str = ft_load_digit_nbr("", temp, opt)))
			str = temp;
		else
			free(temp);
		ft_fill_and_print(str, opt);
		free(str);
	}
}

void	ft_print_hex(va_list ap, t_var *opt, int upper)
{
	unsigned int	nbr;
	char			*str;
	char			*temp;
	char			*before;

	nbr = va_arg(ap, unsigned int);
	before = (opt->hash) ? ft_strdup("0x") : 0;
	if ((temp = ft_to_hex(nbr, upper)))
	{
		if (!(str = ft_load_digit_nbr(before, temp, opt)))
			str = temp;
		else
			free(temp);
		if (opt->hash && opt->fill == '0')
			ft_print_data(&before, opt);
		ft_fill_and_print(str, opt);
		free(str);
	}
	if (before)
		free(before);
}
