/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:35:11 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/12 16:18:06 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *sc;

	while (n > 0)
	{
		sc = (unsigned char *)s;
		if (*sc == (unsigned char)c)
			return ((void *)s);
		s++;
		n--;
	}
	return (NULL);
}
