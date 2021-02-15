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
    int out;
}               t_var;


int ft_printf(const char *format, ...);
void ft_print_char(va_list ap, t_var *opt);
void ft_print_str(va_list ap, t_var *opt);
void ft_print_pointer(va_list ap, t_var *opt);
void ft_print_nbr(va_list ap, t_var *opt);
void ft_print_unsig(va_list ap, t_var *opt);
void ft_print_hex(va_list ap, t_var *opt, int upper);
void ft_fill_and_print(char *str, t_var *opt);
char *ft_to_hex(unsigned int n, int upper);
char		*ft_utoa(unsigned int nbr);
char *ft_pointer_str(unsigned long nbr, int upper);

# endif