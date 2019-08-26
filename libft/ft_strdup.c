/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:19:51 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/12 15:41:38 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		length;

	length = 0;
	while (s1[length])
	{
		length++;
	}
	if ((cpy = (char *)malloc(sizeof(char) * (length + 1))))
	{
		length = 0;
		while (s1[length])
		{
			cpy[length] = s1[length];
			length++;
		}
		cpy[length] = '\0';
		return (cpy);
	}
	return (NULL);
}
