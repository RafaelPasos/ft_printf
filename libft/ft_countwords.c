/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:43:47 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/19 23:01:13 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char *s, char c)
{
	int i;
	int count;
	int size;

	count = 0;
	i = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				if (!(i < size))
					break ;
				i++;
			}
			count++;
		}
		i++;
	}
	return (count);
}
