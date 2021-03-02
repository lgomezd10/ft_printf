/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:53:19 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/03/02 18:45:29 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_opt(t_var *opt)
{
	opt->right = 1;
	opt->len = 0;
	opt->deci = 0;
	opt->fill = ' ';
	opt->dot = 0;
	opt->hash = 0;
	opt->sign = 0;
	opt->space = 0;
	opt->islong = 0;
}

int			ft_is_flags(char c)
{
	int out;

	out = c == '-' || c == '.' || c == '*' || ft_isdigit(c);
	out = out || c == ' ' || c == '+' || c == '#';
	out = out || c == 'h' || c == 'l';
	return (out);
}

void		ft_check_start(va_list ap, t_var *opt)
{
	if (!opt->dot)
	{
		opt->len = va_arg(ap, int);
		if (opt->len < 0)
		{
			opt->len *= -1;
			opt->right = 0;
		}
	}
	else
	{
		opt->deci = va_arg(ap, int);
		opt->dot = (opt->deci < 0) ? 0 : opt->dot;
	}
}

void		ft_check_flag(va_list ap, char c, t_var *opt)
{
	if (c == '-')
		opt->right = 0;
	if (c == '.')
		opt->dot = 1;
	if (c == '0' && !opt->dot)
		opt->fill = '0';
	if (c == '*')
		ft_check_start(ap, opt);
	if (c == '#')
		opt->hash = 1;
	if (c == '+')
		opt->sign = 1;
	if (c == ' ')
		opt->space = 1;
	if (c == 'l')
		opt->islong += 1;
	if (c == 'h')
		opt->islong -= 1;
}

const char	*ft_get_flags(va_list ap, t_var *opt, const char *str)
{
	int i;

	i = 0;
	ft_init_opt(opt);
	while (str[i] && ft_is_flags(str[i]))
	{
		ft_check_flag(ap, str[i], opt);
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
