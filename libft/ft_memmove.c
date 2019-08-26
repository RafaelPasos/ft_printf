/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:25:43 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/18 17:52:46 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	d = dst;
	s = src;
	i = 0;
	if (dst > src)
	{
		i = len;
		while (i--)
		{
			d[i] = s[i];
		}
	}
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
