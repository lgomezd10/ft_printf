/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:32:18 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/01 16:10:01 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *aux;
	t_list *next;

	if (lst && del)
	{
		aux = *lst;
		next = aux->next;
		while (aux != 0)
		{
			ft_lstdelone(aux, del);
			aux = next;
			next = (aux == 0) ? 0 : aux->next;
		}
		*lst = 0;
	}
}
