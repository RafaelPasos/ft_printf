/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 01:45:30 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/23 03:37:59 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void    get_precision(t_printf *data)
{
	while (data->formatstring[data->i] == '.')
	{
		data->i++;
		data->precision = 0;
		while (data->formatstring[data->i] >= '0' && data->formatstring[data->i] <= '9')
		{
			data->precision *= 10;
			data->precision += (data->formatstring[data->i] - 48);
			data->i++;
		}
	}
}