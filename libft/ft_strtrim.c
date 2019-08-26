/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 02:32:01 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 05:35:57 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) == 0)
		return ((char *)s);
	j = ft_strlen(s) - 1;
	while (s[i] && ((s[i] == '\t') || (s[i] == '\n') || (s[i] == ' ')))
		i++;
	while ((j > i) && ((s[j] == '\t') || (s[j] == '\n') || (s[j] == ' ')))
		j--;
	if ((j - i) > 1)
		size = (j - i + 1);
	else
		size = 1;
	str = ft_strsub(s, i, size);
	return (str);
}
