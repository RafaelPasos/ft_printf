/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 00:22:21 by apasos-g          #+#    #+#             */
/*   Updated: 2019/09/08 14:49:03 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_it(t_printf *data)
{
	int	ordinary_chars;

	ordinary_chars = 0;
	if (ft_strcmp(data->formatstring, "%") != 0)
	{
		while (data->formatstring[data->i])
		{
			if (data->formatstring[data->i] == '%')
			{
				print_normalstr(data, ordinary_chars);
				reset(data);
				convert_specifier(data);
				ordinary_chars = 0;
			}
			else
			{
				ordinary_chars++;
				data->len++;
			}
			data->i++;
		}
		print_normalstr(data, ordinary_chars);
	}
}

int		ft_printf(const char *format, ...)
{
	t_printf	data;

	va_start(data.args, format);
	initialize(&data, format);
	if (format)
		print_it(&data);
	va_end(data.args);
	return (data.len);
}