/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:56:25 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/08 19:19:25 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	strlen;
	char	*s1;
	char	*s2;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	strlen = ft_strlen(s2);
	if (!strlen)
		return (s1);
	i = 0;
	while (i < len && s1[i] != '\0')
	{
		if ((i + strlen <= len) && !ft_strncmp(&s1[i], s2, strlen))
			return (&s1[i]);
		i++;
	}
	return (0);
}
