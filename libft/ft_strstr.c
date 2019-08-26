/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:06:03 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/12 15:44:40 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int found;

	i = -1;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i])
	{
		found = 1;
		while (needle[j])
		{
			if (haystack[i + j] != needle[j])
				found = 0;
			j++;
		}
		if (found)
			return ((char *)&haystack[i]);
		j = 0;
	}
	return (NULL);
}
