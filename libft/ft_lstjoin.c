/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:26:39 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/27 20:08:53 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstjoin(t_list **alst, t_list **blst)
{
	t_list *iter;

	if (!alst)
		return (*alst);
	if (!blst)
		return (*alst);
	iter = *alst;
	while (iter->next)
		iter = iter->next;
	iter->next = *blst;
	return (*alst);
}
