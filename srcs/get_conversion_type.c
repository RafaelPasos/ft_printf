/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 01:46:50 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/25 20:07:48 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		get_conversion_type(t_printf *data)
{
	int		i;

	i = 0;
	while (data->conversion_mask[i])
	{
		if (data->conversion_mask[i] == data->formatstring[data->i])
		{
			data->conversion = data->conversion_mask[i];
			return ;
		}
		i++;
	}
}