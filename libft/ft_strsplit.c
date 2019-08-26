/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:30:48 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 05:41:20 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char *s, char c)
{
	char	**split;
	int		words;
	int		i;
	int		wordsize;
	int		posword;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	if (!(split = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	while (i < words)
	{
		wordsize = ft_wordsize(s, c, i);
		posword = ft_posword(s, c, i);
		if (!(split[i] = (char *)malloc(sizeof(char) * (wordsize + 1))))
			return (NULL);
		split[i] = ft_strsub(s, posword, wordsize);
		i++;
	}
	split[i] = NULL;
	return (split);
}
