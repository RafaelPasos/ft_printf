/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_posword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:42:19 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/12 16:42:50 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_posword(char *s, char c, int word)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && (s[i] != c))
			{
				if (word == count)
					return (i);
				i++;
			}
			count++;
		}
		i++;
	}
	return (i);
}
