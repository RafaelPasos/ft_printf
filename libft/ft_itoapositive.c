/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoapositive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:14:25 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 06:01:34 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoapositive(int nbr)
{
	int		digits;
	int		nbrcpy;
	char	*snbr;

	digits = 0;
	nbrcpy = nbr;
	while (nbrcpy > 0)
	{
		nbrcpy = nbrcpy / 10;
		digits++;
	}
	if (!(snbr = malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	snbr[digits] = '\0';
	while (digits > 0)
	{
		snbr[digits - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		digits--;
	}
	return (snbr);
}
