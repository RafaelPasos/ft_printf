/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:39:39 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/15 18:31:46 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned const char *s;
	unsigned char		cmp;
	size_t				i;

	d = dst;
	s = src;
	i = 0;
	cmp = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == cmp)
		{
			i++;
			return (&d[i]);
		}
		i++;
	}
	return (NULL);
}
