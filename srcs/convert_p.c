/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 04:14:09 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/25 20:05:55 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		convert_p(t_printf *data)
{
	char		*to_print;
	intptr_t	number;
	int			length;

	number = va_arg(data->args, intptr_t);
	to_print = make_hex(number);
	if (!to_print)
		length = 3;
	else
		length = ft_strlen(to_print) + 2;
	if (data->flag[0] != '-')
		padding(data, ' ', data->field_width - length);
	if (!to_print)
		ft_putstr("0x0");
	else
	{
		ft_putstr("0x");
		ft_putstr(to_print);
	}
	if (data->flag[0] == '-')
		padding(data, ' ', data->field_width - length);
	data->len += length;
	free(to_print);
}