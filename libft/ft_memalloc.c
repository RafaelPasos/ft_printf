/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:35:32 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 03:55:34 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*alloc;
	size_t			i;

	if (!(alloc = malloc(sizeof(void) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		alloc[i] = 0;
		i++;
	}
	return (alloc);
}
