/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:41 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/21 08:45:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void ft_print_char(va_list ap, t_var *opt)
{
	char c;
	char *str;

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
	ft_putchar_fd('%', 1);
	opt->out++;
	/*
	char *str;


	str = ft_calloc(sizeof(char), 2);
	if (str)
	{
		if (opt->start)
			opt->len = va_arg(ap, int);
		if (!opt->right)
			opt->fill = ' ';
		if (opt->dot)
			opt->len = opt->deci;
		str[0] = '%';
		ft_fill_and_print(str, opt);
		free(str);
	}
	*/
}

void ft_print_str(va_list ap, t_var *opt)
{
	char *str;
	char *delete;
	
	delete = 0;
	opt->fill = ' ';
	if (!(str = (char *)va_arg(ap, const char *)))
	{
		str = ft_strdup("(null)");
		delete = str;
	}
	if (opt->dot)
	{    
		if ((str = ft_substr(str, 0, opt->deci)))
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
	
	p = va_arg(ap, void *);	
	if ((temp = ft_pointer_str((unsigned long)p, 0)))
	{
		str = (p) ? ft_load_digit_nbr("0x", temp, opt) : ft_load_digit_nbr("", temp, opt);
		if (!str)
			str = temp;
		else
			free(temp);
		if (opt->fill == '0')
		{
			ft_putstr_fd("0x", 1);
			opt->len -= 2;
			opt->out += 2;
		}
		ft_fill_and_print(str, opt);
		free(str);
	}
}