/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:18:59 by apasos-g          #+#    #+#             */
/*   Updated: 2018/12/14 20:17:58 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *assign;

	assign = (unsigned char *)b;
	while (len > 0)
	{
		*assign = (unsigned char)c;
		assign++;
		len--;
	}
	return (b);
}
