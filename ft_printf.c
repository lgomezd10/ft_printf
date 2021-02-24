/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:15:56 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/24 19:59:21 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

const char	*ft_print_variable(const char *str, va_list ap, t_var *opt)
{
	int d;
	char c;

	if (*str == '%')
		ft_print_percent(ap, opt);
	if (*str == 'c')
		ft_print_char(ap, opt);
	if (*str == 's')
		ft_print_str(ap, opt);
	if (*str == 'p')
		ft_print_pointer(ap, opt);
	if (*str == 'd' || *str == 'i')
		ft_print_nbr(ap, opt);
	if (*str == 'u')
		ft_print_unsig(ap, opt);
	if (*str == 'x')
		ft_print_hex(ap, opt, 0);
	if (*str == 'X')
		ft_print_hex(ap, opt, 1);
	if (*str == 'n')
		ft_save_len(ap, opt);
	if (*str == 'f' || *str == 'e' || *str == 'g')
		ft_print_double(ap, opt, *str);
	return ((str + 1));
}



int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	t_var	opt;

	opt.out = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			format = ft_get_flags(ap, &opt, &format[++i]);
			format = ft_print_variable(format, ap, &opt);
			i = 0;
		}
		else
		{
			ft_putchar_fd(format[i++], 1);
			opt.out++;
		}
	}
	va_end(ap);
	return (opt.out);
}
