/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:45:36 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/28 05:20:18 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	cpy = ft_strndup((char *)haystack, len);
	while (*cpy != '\0')
	{
		if (ft_strncmp((char *)cpy, needle, ft_strlen(needle)) == 0)
			return ((char *)&haystack[i]);
		cpy++;
		i++;
	}
	return (NULL);
}
