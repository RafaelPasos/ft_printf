/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 02:07:59 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 05:47:52 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		it;

	i = 0;
	j = 0;
	it = 0;
	if (!(s1 && s2))
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	i = i + j;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = -1;
	while (s1[++j])
		str[it++] = s1[j];
	j = -1;
	while (s2[++j])
		str[it++] = s2[j];
	str[it] = '\0';
	return (str);
}
