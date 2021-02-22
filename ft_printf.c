/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:15:56 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/22 08:47:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

//cspdiuxX % x y X conversion hexadeci sin signo
const char	*ft_print_variable(const char *str, va_list ap, t_var *opt)
{
	int d;
	char c;
// nfge
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
	if (*str == 'f')
		ft_print_float(ap, opt);
	return ((str + 1));
}

void	ft_init_opt(t_var *opt)
{
	opt->fill = ' ';
	opt->len = 0;
	opt->right = 1;
	opt->dot = 0;
	opt->deci = 0;
	opt->hash = 0;
	opt->sign = 0;
}

int ft_is_flags(char c)
{
	int out;

	out = c == '-' || c == '.' || c == '*' || ft_isdigit(c);
	out = out || c == ' ' || c == '+' || c == '#';

	return (out);
}

const char	*ft_get_flags(va_list ap, t_var *opt, const char *str)
{
	int i;

	i = 0;
	ft_init_opt(opt);
	while (ft_is_flags(str[i]))
	{
		if (str[i] == '-')
			opt->right = 0;
		if (str[i] == '.')
			opt->dot = 1;
		if (str[i] == '#')
			opt->hash = 1;
		if (str[i] == '+')
			opt->sign = 1;
		if (str[i] == ' ')
			opt->space = 1;
		if (str[i] == '0' && !opt->dot)
			opt->fill = '0';
		if (str[i] == '*' && !opt->dot)
			opt->len = va_arg(ap, int);
		if (str[i] == '*' && opt->dot)
			opt->deci = va_arg(ap, int);			
		if (ft_isdigit(str[i]) && (str[i] != 0 || opt->dot))
		{
			opt->len = (!opt->dot) ? ft_atoi(&str[i]) : opt->len;
			opt->deci = (opt->dot) ? ft_atoi(&str[i]) : opt->deci;
			while (ft_isdigit(str[i]))
				i++;
			i--;
		}
		i++;
	}
	return (&str[i]);
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
