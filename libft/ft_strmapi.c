/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 00:36:59 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 05:29:31 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		if (!(map = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			map[i] = (*f)(i, s[i]);
			i++;
		}
		map[i] = '\0';
		return (map);
	}
	return (NULL);
}
