/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoanegative.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:15:06 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 06:51:40 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoanegative(int nbr)
{
	char	*conv;
	int		i;
	char	*snbr;
	int		digits;

	digits = 1;
	i = 0;
	if (!(snbr = ft_itoapositive(nbr * -1)))
		return (NULL);
	while (snbr[i])
	{
		digits++;
		i++;
	}
	if (!(conv = malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	conv[digits] = '\0';
	conv[0] = '-';
	i = 0;
	while (snbr[i])
	{
		conv[i + 1] = snbr[i];
		i++;
	}
	return (conv);
}
