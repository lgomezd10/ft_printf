/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:53:43 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/03/02 15:54:42 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_load_before(t_var *opt, int isneg)
{
	char *str;

	str = (isneg) ? ft_strdup("-") : 0;
	str = (opt->space && !opt->sign && !isneg) ? ft_strdup(" ") : str;
	str = (opt->sign && !isneg) ? ft_strdup("+") : str;
	return (str);
}

char	*ft_load_digit_nbr(char *before, char *nbr, t_var *opt)
{
	int		lnbr;
	int		lbefore;
	int		lzeros;
	char	*new;

	new = 0;
	opt->fill = (!opt->right || opt->dot) ? ' ' : opt->fill;
	if (opt->dot || (!opt->dot && opt->fill != '0'))
	{
		lbefore = (before) ? ft_strlen(before) : 0;
		lnbr = (nbr) ? ft_strlen(nbr) : 0;
		while (opt->dot && opt->deci < lnbr && *nbr == '0')
		{
			nbr++;
			lnbr--;
		}
		lzeros = (opt->dot && lnbr < opt->deci) ? opt->deci - lnbr : 0;
		new = (char *)ft_calloc(sizeof(char), lbefore + lnbr + lzeros + 1);
		ft_memset(new, '0', lbefore + lnbr + lzeros);
		if (before)
			ft_memcpy(new, before, lbefore);
		ft_memcpy(&new[lbefore + lzeros], nbr, lnbr);
		opt->dot = 0;
	}
	return (new);
}

void	ft_print_any_nbr(char **before, char **nbr, t_var *opt, int isneg)
{
	char *str;

	if (*nbr)
	{
		if (!(str = ft_load_digit_nbr(*before, *nbr, opt)))
			str = *nbr;
		else
		{
			free(*nbr);
			*nbr = 0;
		}
		if (opt->fill == '0' && (isneg || opt->sign || opt->space))
			ft_print_data(before, opt);
		ft_fill_and_print(str, opt);
		if (str)
			free(str);
	}
}
