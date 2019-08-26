/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 03:13:58 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/25 20:05:31 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include "stdio.h"

void	convert_c(t_printf *data)
{
	char	c;

	c = (char)va_arg(data->args, int);
	if (data->flag[0] != '-')
		padding(data, ' ', data->field_width - 1);
	write(1, &c, 1);
	data->len++;
	if (data->flag[0] == '-')
		padding(data, ' ', data->field_width - 1);
}
