/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 02:43:16 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 07:38:28 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*tofree;

	tofree = *alst;
	while (!(tofree->next == NULL))
	{
		node = tofree->next;
		(*del)(tofree->content, tofree->content_size);
		free(tofree);
		tofree = node;
	}
	(*del)(tofree->content, tofree->content_size);
	free(tofree);
	tofree = NULL;
	*alst = NULL;
}
