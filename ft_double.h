#ifndef FT_DOUBLE_H
# define FT_DOUBLE_H
# include "ft_printf.h"
# define MAX_SUPPORT 1.79769313486231571e+308/*9218868437227405318.0*/


typedef long long int			t_llint;
typedef unsigned long long int	t_ullint;
typedef struct					s_double
{
	long double	fnbr;
	long double	fnbr_exp;
	t_ullint	nbr;
	int			isneg;
	char		*str_nbr;
	char		*str_deci;
	int			cut;
	int			exp;
}								t_double;

void							ft_add_one(t_double *data);
void							ft_add_exp(char **str, int exp);
void							ft_get_decimal(t_double *data, t_var *opt);
void							ft_clear_zeros(t_double *data, t_var *opt);
char							*ft_join(t_double *data, t_var *opt);
int								ft_get_exp(t_double *data);

#endif
