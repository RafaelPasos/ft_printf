/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:33:11 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/15 18:31:00 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t des_it;
	size_t src_it;

	des_it = 0;
	src_it = 0;
	while (s1[des_it])
		des_it++;
	while ((s2[src_it]) && (src_it < n))
	{
		s1[des_it] = s2[src_it];
		src_it++;
		des_it++;
	}
	s1[des_it] = '\0';
	return (s1);
}
