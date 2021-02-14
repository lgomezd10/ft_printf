#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

//’-0.*’
typedef struct s_var
{
    int right;
    int len;
    char fill;
    int dot;
    int start;
}               t_var;


int ft_printf(const char *format, ...);
void ft_print_char(va_list ap, t_var *opt);
void ft_print_str(va_list ap, t_var *opt);
void ft_print_pointer(va_list ap, t_var *opt);
void ft_print_nbr(va_list ap, t_var *opt);
void ft_print_unsig(va_list ap, t_var *opt);
void ft_print_hex(va_list ap, t_var *opt);
void ft_fill_and_print(char *str, t_var *opt);

# endif