/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 02:40:02 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/26 04:08:53 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_lltoapositive(long long nbr)
{
	long long	digits;
	long long	nbrcpy;
	char		*snbr;

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

char	*ft_lltoanegative(long long nbr)
{
	char		*conv;
	long long	i;
	char		*snbr;
	long long	digits;

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

char	*ft_lltoa(long long nbr)
{
	if (nbr == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr > 0)
		return (ft_lltoapositive(nbr));
	else
		return (ft_lltoanegative(nbr));
}