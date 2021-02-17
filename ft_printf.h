/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:13 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/17 07:51:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct  s_var
{
    int right;
    int len;
    int decimal;
    char fill;
    int dot;
    int start;
    int out;
}               t_var;

int             ft_printf(const char *format, ...);
void            ft_print_percent(va_list ap, t_var *opt);
void            ft_print_char(va_list ap, t_var *opt);
void            ft_print_str(va_list ap, t_var *opt);
void            ft_print_pointer(va_list ap, t_var *opt);
void            ft_print_nbr(va_list ap, t_var *opt);
void            ft_print_unsig(va_list ap, t_var *opt);
void            ft_print_hex(va_list ap, t_var *opt, int upper);
void            ft_fill_and_print(char *str, t_var *opt);
char            *ft_to_hex(unsigned int n, int upper);
char            *ft_utoa(unsigned int nbr);
char            *ft_pointer_str(unsigned long nbr, int upper, int zero);
void            ft_save_len(va_list ap, t_var *opt);

# endif