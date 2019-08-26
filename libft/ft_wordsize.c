/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:43:06 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/12 16:43:22 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordsize(char *s, char c, int word)
{
	int i;
	int count;
	int size;

	i = 0;
	count = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && (s[i] != c))
			{
				if (word == count)
					size++;
				i++;
			}
			count++;
		}
		i++;
	}
	return (size);
}
