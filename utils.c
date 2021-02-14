#include "ft_printf.h"

void ft_fill_and_print(char *str, t_var *opt)
{
    int len;
    int i;

    len = ft_strlen(str);
    len = (len < opt->len) ? (opt->len - len) : 0;
    if (!opt->right)
        ft_putstr_fd(str, 1);
    i = 0;
    while (i++ < len)
        ft_putchar_fd(opt->fill, 1);
    if (opt->right)
        ft_putstr_fd(str, 1);
}