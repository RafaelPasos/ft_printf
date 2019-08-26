/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 00:53:56 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/21 06:46:50 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr > 0)
		return (ft_itoapositive(nbr));
	else
		return (ft_itoanegative(nbr));
}
