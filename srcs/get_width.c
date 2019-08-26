/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 01:44:43 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/25 05:37:12 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void    get_width(t_printf *data)
{
	while (data->formatstring[data->i] >= '0' && data->formatstring[data->i] <= '9')
	{
		data->field_width *= 10;
		data->field_width += (data->formatstring[data->i] - 48);
		data->i++;
	}
}