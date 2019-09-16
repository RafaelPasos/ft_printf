/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:37:26 by apasos-g          #+#    #+#             */
/*   Updated: 2019/09/08 02:26:29 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_ulltoa(unsigned long long nbr)
{
	unsigned long long	digits;
	unsigned long long	nbrcpy;
	char		*snbr;

	if (nbr == 0)
		return (ft_strdup("0"));
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