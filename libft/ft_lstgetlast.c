/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:33:49 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 18:30:12 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgetlast(t_list **alst)
{
	t_list *node;

	if (!alst)
		return (NULL);
	node = *alst;
	while (node->next)
		node = node->next;
	return (node);
}
