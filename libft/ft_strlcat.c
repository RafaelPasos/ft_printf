/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:14:39 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/19 06:28:52 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dl;
	size_t		sl;
	size_t		i;

	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dl > dstsize)
		return (dstsize + sl);
	i = 0;
	while ((dl + i + 1 < dstsize) && (src[i] != 0))
	{
		dst[dl + i] = src[i];
		i++;
	}
	if (dl + i < dstsize)
		dst[dl + i] = 0;
	return (dl + sl);
}
