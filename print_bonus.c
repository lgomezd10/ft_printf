#include "ft_printf.h"

void ft_save_len(va_list ap, t_var *opt)
{
    int *len;

    len = va_arg(ap, int *);
    *len = opt->out;
}