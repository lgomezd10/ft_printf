#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void ft_print_char(va_list ap, t_var *opt)
{
	char c;

    c = (char)va_arg(ap, int);
    ft_putchar_fd(c, 1);
    opt->out++;
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
        ft_putstr_fd("(null)", 1);
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

    p = va_arg(ap, void *);
    str = ft_pointer_str((unsigned long)p, 0);
    if (str)
        ft_fill_and_print(str, opt);
    free(str);
}