/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 03:03:10 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/14 03:17:26 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *list;

	list = NULL;
	if (lst != NULL)
	{
		temp = (*f)(lst);
		list = ft_lstnew(temp->content, temp->content_size);
		if (lst->next != NULL)
		{
			lst = lst->next;
			while (lst->next != NULL)
			{
				temp = (*f)(lst);
				ft_lstaddback(&list, temp);
				lst = lst->next;
			}
			temp = (*f)(lst);
			ft_lstaddback(&list, temp);
		}
	}
	return (list);
}
