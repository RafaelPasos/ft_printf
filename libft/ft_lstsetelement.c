/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsetelement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:43:44 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 18:19:39 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsetelement(t_list **alst, size_t i, void *data, size_t cs)
{
	t_list *node;
	size_t j;

	j = 0;
	if (alst && data)
	{
		if (i < ft_lstsize(alst))
		{
			node = *alst;
			while (node->next)
			{
				if (i == j)
				{
					free(node);
					node = ft_lstnew(data, cs);
				}
				j++;
				node = node->next;
			}
		}
	}
	node = NULL;
}
