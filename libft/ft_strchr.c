/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:51:41 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/01/26 15:52:32 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char*)s;
	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == '\0' && c != '\0')
		return (0);
	return ((char *)&str[i]);
}
