/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 00:43:39 by apasos-g          #+#    #+#             */
/*   Updated: 2019/09/05 03:35:28 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void    initialize(t_printf *data, const char *format)
{
	data->formatstring = (char *)format;
	data->i = 0;
	data->len = 0;
	data->conversion_mask = "sScdiuoxXpf%";
	data->flag_mask = "-+ 0#";
	data->length_mask = "lhL";
	data->num_positive = 1;
}

void    reset(t_printf *data)
{
	data->flag[0] = '\0';
	data->flag[1] = '\0';
	data->flag[2] = '\0';
	data->flag[3] = '\0';
	data->flag[4] = '\0';
	data->length[0] = '\0';
	data->length[1] = '\0';
	data->length[2] = '\0';
	data->conversion = '\0';
	data->field_width = 0;
	data->precision = -1;
	data->num_positive = 1;
}