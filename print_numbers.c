/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:58 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/22 18:36:47 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>



void	ft_print_nbr(va_list ap, t_var *opt)
{
	long long int lld;
	unsigned long long int	usig;
	char		*temp;
	char		*before;	
	
	if (!opt->islong)
		lld = (long int)va_arg(ap, int);
	else if (opt->islong == 1)
		lld = va_arg(ap, long int);
	else
		lld = va_arg(ap, long int);
	before = ft_load_before(opt, lld < 0);
	usig = (lld < 0) ? lld * -1 : lld;
	temp = ft_llitoa(usig);
	ft_print_any_nbr(&before, &temp, opt, lld < 0);	
	if (before)
		free(before);
}

void	ft_print_unsig(va_list ap, t_var *opt)
{
	int				d;
	unsigned long int	ud;
	char			*str;
	char			*temp;

	if (!opt->islong)
		ud = va_arg(ap, unsigned int);
	else if (opt->islong == 1)
		ud = va_arg(ap, unsigned long int);
	else
		ud = va_arg(ap, unsigned long long int);
	if ((temp = ft_ultoa(ud)))
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
	unsigned long long int	nbr;
	char			*str;
	char			*temp;
	char			*before;

	if (!opt->islong)
		nbr = va_arg(ap, unsigned int);
	else if (opt->islong == 1)
		nbr = va_arg(ap, unsigned long int);
	else
		nbr = va_arg(ap, unsigned long long int);
	before = (opt->hash && nbr && !upper) ? ft_strdup("0x") : 0;
	before = (opt->hash && nbr && upper) ? ft_strdup("0X") : before;
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
