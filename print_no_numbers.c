/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:41 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/22 13:28:21 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void ft_print_char(va_list ap, t_var *opt)
{
	char c;

	c = (char)va_arg(ap, int);
	opt->fill = ' ';
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
	char c;

	c = '%';
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

void ft_print_str(va_list ap, t_var *opt)
{
	char *str;
	char *delete;

	delete = 0;
	opt->fill = ' ';
	if (!(str = (char *)va_arg(ap, const char *)))
	{
		if ((str = ft_strdup("(null)")))
			delete = str;
	}
	if (opt->dot)
	{    
		if (str && (str = ft_substr(str, 0, opt->deci)))
		{
			ft_fill_and_print(str, opt);
			free(str);
		}
	}
	else
		ft_fill_and_print((char *)str, opt);
	if (delete)
		free(delete);
}

void ft_print_pointer(va_list ap, t_var *opt)
{
	void	*p;
	char	*str;
	char	*temp;
	char	*before;

	p = va_arg(ap, void *);	
	before = ft_strdup("0x");
	if ((temp = ft_pointer_str((unsigned long)p, 0)))
	{
		if (!(str = ft_load_digit_nbr(before, temp, opt)))
			str = temp;
		else
			free(temp);
		if (opt->fill == '0')
			ft_print_data(&before, opt);
		ft_fill_and_print(str, opt);
		if (str)
			free(str);
	}
	if (before)
		free(before);
}