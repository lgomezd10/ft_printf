/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:41 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/16 18:11:14 by lgomez-d         ###   ########.fr       */
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
    str = ft_calloc(sizeof(char), 2);
    if (str)
    {
        if (!opt->right)
            opt->fill = ' ';
        if (opt->dot)
            opt->len = 1;
        str[0] = c;
        ft_fill_and_print(str, opt);
        free(str);
    }
    /*
    ft_putchar_fd(c, 1);
    opt->out++;
    */
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
            opt->len = 1;
        str[0] = '%';
        ft_fill_and_print(str, opt);
        free(str);
    }
}

void ft_print_str(va_list ap, t_var *opt)
{
	const char *str;
    char *subs;
    char *out;

    if (opt->start)
        opt->len = va_arg(ap, int);
    str = va_arg(ap, const char *);
    if (!str)
    {
        ft_putstr_fd("(null)", 1);
        opt->out += 6;
    }
    else
    {
        opt->fill = ' ';
        if (opt->dot && opt->len < ft_strlen(str))
        {
            subs = ft_substr(str, 0, opt->len);
            if (subs)
            {
                ft_fill_and_print(subs, opt);
                free(subs);
            }
        }
        else
            ft_fill_and_print((char *)str, opt);
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
    if (opt->dot)
    {
        opt->fill = '0';
        opt->len += 2;
    }
    zero = (opt->fill == '0') ? 1 : 0;
    if (zero)
    {
        ft_putstr_fd("0x", 1);
        opt->len -= 2;
        opt->out += 2;
    }
    str = ft_pointer_str((unsigned long)p, 0, zero);
    if (str)
    {
        ft_fill_and_print(str, opt);
        free(str);
    }
}