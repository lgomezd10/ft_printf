/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:12:21 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/01/22 16:13:07 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_load_str(char *str, int size, int n)
{
	unsigned int nbr;

	if (n < 0)
		str[0] = '-';
	nbr = (n < 0) ? n * -1 : n;
	size--;
	str[size] = '\0';
	while (nbr / 10 != 0)
	{
		str[--size] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	str[size - 1] = (nbr % 10) + '0';
	return (str);
}

char		*ft_itoa(int n)
{
	int				i;
	int				size;
	unsigned int	nbr;
	char			*str;

	i = 1;
	nbr = (n < 0) ? n * -1 : n;
	while (nbr / 10 != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	size = (n < 0) ? i + 2 : i + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (str)
		str = ft_load_str(str, size, n);
	return (str);
}
