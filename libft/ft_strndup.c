/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 01:02:01 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/28 02:18:17 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, size_t len)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (!(cpy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
