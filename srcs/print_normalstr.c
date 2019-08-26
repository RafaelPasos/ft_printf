/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normalstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 01:33:38 by apasos-g          #+#    #+#             */
/*   Updated: 2019/08/23 03:42:12 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_normalstr(t_printf *data, int ordinary_chars)
{
	char	*toprint;

	toprint = NULL;
	if (ordinary_chars > 0)
	{
		if ((toprint = ft_strndup((data->formatstring + (data->i - ordinary_chars)), ordinary_chars)))
		{
			ft_putstr(toprint);
			free(toprint);
		}
		toprint = NULL;
	}
}