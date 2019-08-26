/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 01:46:05 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/25 20:29:18 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void    get_length(t_printf *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->length_mask[i] != '\0')
	{
		while (data->length_mask[i] == data->formatstring[data->i])
		{
			data->length[j] = data->formatstring[data->i];
			data->length[j + 1] = '\0';
			data->i++;
			j++;
		}
		i++;
	}
}