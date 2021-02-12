/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:42:59 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/02 20:26:34 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	real_len;
	char	*str;

	if (len < 0 || !s)
		return (0);
	real_len = (start >= ft_strlen(s)) ? 0 : ft_strlen(&s[start]);
	len = (real_len < len) ? real_len : len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
		ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
