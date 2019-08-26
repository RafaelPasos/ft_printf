/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 01:15:22 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 05:44:07 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!(s1 && s2))
		return (0);
	while (s1[i] && (i < n))
	{
		if (s2[i])
		{
			if (s1[i] > s2[i])
				return (0);
			if (s1[i] < s2[i])
				return (0);
		}
		else
			return (0);
		if (!(s1[i + 1]))
			if (s2[i + 1])
				return (0);
		i++;
	}
	return (1);
}
