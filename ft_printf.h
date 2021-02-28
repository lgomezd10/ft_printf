/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:11:13 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/26 08:27:25 by user42           ###   ########.fr       */
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
	int deci;
	char fill;
	int dot;
	int hash;
	int sign;
	int space;
	int islong;
	int out;
}               t_var;

int             ft_printf(const char *format, ...);
const char		*ft_get_flags(va_list ap, t_var *opt, const char *str);
void            ft_print_percent(va_list ap, t_var *opt);
void            ft_print_char(va_list ap, t_var *opt);
void            ft_print_str(va_list ap, t_var *opt);
void            ft_print_pointer(va_list ap, t_var *opt);
void            ft_print_nbr(va_list ap, t_var *opt);
void            ft_print_unsig(va_list ap, t_var *opt);
void            ft_print_hex(va_list ap, t_var *opt, int upper);
void            ft_fill_and_print(char *str, t_var *opt);
char			*ft_to_hex(unsigned long long int nbr, int upper);
char			*ft_ultoa(unsigned long long int nbr);
char            *ft_pointer_str(unsigned long nbr, int upper);
void            ft_save_len(va_list ap, t_var *opt);
char            *ft_load_digit_nbr(char *before, char *nbr, t_var *opt);
void			ft_print_data(char **str, t_var *opt);
void			ft_print_double(va_list ap, t_var *opt, char t);
char			*ft_load_before(t_var *opt, int isneg);
void			ft_print_any_nbr(char **before, char **nbr, t_var *opt, int isneg);

# endif