/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 04:07:50 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/25 20:10:17 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		convert_percent(t_printf *data)
{
	if (data->flag[3] == '0')
	{
		if (data->flag[0] != '-')
			padding(data, '0', data->field_width - 1);
		write(1, "%", 1);
		if (data->flag[0] == '-')
			padding(data, ' ', data->field_width - 1);
	}
	else
	{
		if (data->flag[0] != '-')
			padding(data, ' ', data->field_width - 1);
		write(1, "%", 1);
		if (data->flag[0] == '-')
			padding(data, ' ', data->field_width - 1);
	}
	data->len++;
}