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
};


int ft_printf(const char *format, ...);

# endif