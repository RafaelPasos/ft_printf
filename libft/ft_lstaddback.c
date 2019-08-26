/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:35:43 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 07:54:40 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list *list;

	list = *alst;
	if (list == NULL)
		list = new;
	else
	{
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
}
