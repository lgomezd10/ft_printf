/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:42:59 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/12 08:09:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	real_len;
	char	*str;

	if (!s)
		return (0);
	real_len = (start >= ft_strlen(s)) ? 0 : ft_strlen(&s[start]);
	len = (real_len < len) ? real_len : len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
		ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
