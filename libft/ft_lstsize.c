/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:37:39 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/27 20:09:41 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list **alst)
{
	size_t	i;
	t_list	*node;

	i = 1;
	if (!alst)
		return (0);
	node = *alst;
	while (node->next)
	{
		node = node->next;
		i++;
	}
	return (i);
}
