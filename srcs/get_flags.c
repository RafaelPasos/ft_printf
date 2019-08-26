/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 01:44:07 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/25 19:29:12 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void    get_flags(t_printf *data)
{
	int i;

	i = 0;
	while (data->flag_mask[i] != '\0')
	{
		while (data->flag_mask[i] == data->formatstring[data->i])
		{
			while (data->formatstring[data->i] == '-' && data->i++)
				data->flag[0] = '-';
			while (data->formatstring[data->i] == '+' && data->i++)
				data->flag[1] = '+';
			while (data->formatstring[data->i] == ' ' && data->i++)
				data->flag[2] = ' ';
			while (data->formatstring[data->i] == '0' && data->i++)
				data->flag[3] = '0';
			while (data->formatstring[data->i] == '#' && data->i++)
				data->flag[4] = '#';
			i = 0;
		}
		i++;
	}
}