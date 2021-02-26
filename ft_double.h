#ifndef FT_DOUBLE_H
# define FT_DOUBLE_H
# include "ft_printf.h"

typedef long long int			t_llint;
typedef unsigned long long int	t_ullint;
typedef struct					s_double
{
	long double	fnbr;
	t_ullint	nbr;
	int			isneg;
	char		*str_nbr;
	char		*str_deci;
	int			cut;
}								t_double;

void							ft_add_one(t_double *data);
void							ft_add_exp(char **str, int exp);
void							ft_get_decimal(t_double *data, t_var *opt);
void							ft_clear_zeros(t_double *data, t_var *opt);
char							*ft_join(t_double *data, t_var *opt);

#endif
