/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 02:21:30 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 18:10:59 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*node;
	unsigned char	*contentl;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
		return (node);
	}
	else
	{
		if (!(contentl = (unsigned char *)malloc(sizeof(content_size))))
		{
			free(node);
			return (NULL);
		}
		ft_memcpy(contentl, content, content_size);
		node->content = contentl;
		node->content_size = content_size;
		node->next = NULL;
		return (node);
	}
}
