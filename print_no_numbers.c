/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:41 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/18 08:50:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void ft_print_char(va_list ap, t_var *opt)
{
	char c;
	char *str;

	if (opt->start)
		opt->len = va_arg(ap, int);
	c = (char)va_arg(ap, int);
	opt->len--;
	if (opt->right)
	{		
		ft_fill_and_print("", opt);	
		ft_putchar_fd(c, 1);
	}
	else
	{
		opt->fill = ' ';
		ft_putchar_fd(c, 1);
		ft_fill_and_print("", opt);
	}
	opt->out++;
}

void ft_print_percent(va_list ap, t_var *opt)
{
	char *str;

	str = ft_calloc(sizeof(char), 2);
	if (str)
	{
		if (opt->start)
			opt->len = va_arg(ap, int);
		if (!opt->right)
			opt->fill = ' ';
		if (opt->dot)
			opt->len = opt->decimal;
		str[0] = '%';
		ft_fill_and_print(str, opt);
		free(str);
	}
}

void ft_print_str(va_list ap, t_var *opt)
{
	char *str;
	char *out;

	if (opt->start)
		opt->len = va_arg(ap, int);
	if (!opt->right)
		opt->fill = ' ';
	if (!(str = (char *)va_arg(ap, const char *)))
	{
		str = ft_strdup("(null)");
		ft_fill_and_print(str, opt);
		free (str);
	}
	else
	{
		if (opt->dot)
		{    
			if ((str = ft_substr(str, 0, opt->decimal)))
			{
				ft_fill_and_print(str, opt);
				free(str);
			}
		}
		else
			ft_fill_and_print((char *)str, opt);
	}
	
}

void ft_check_decimal(void *p, t_var *opt)
{
	char *str;

	if ((str = ft_pointer_str((unsigned long)p, 0, 0)))
		if (opt->dot && ft_strlen(str) < opt->decimal)
		{
			opt->fill = '0';
			opt->len = opt->decimal + 2;
			opt->right = 1;
			free(str);
		}
}

void ft_print_pointer(va_list ap, t_var *opt)
{
	void *p;
	char *str;
	int zero;

	if (opt->start)
		opt->len = va_arg(ap, int);
	p = va_arg(ap, void *);
	opt->fill = (!opt->right) ? ' ' : opt->fill;
	ft_check_decimal(p, opt);
	opt->dot = 0;	
	if ((zero = (opt->fill == '0') ? 1 : 0))
	{
		ft_putstr_fd("0x", 1);
		opt->len -= 2;
		opt->out += 2;
	}	
	if ((str = ft_pointer_str((unsigned long)p, 0, zero)))
	{
		ft_fill_and_print(str, opt);
		free(str);
	}
}