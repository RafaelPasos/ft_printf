/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 01:42:20 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/26 04:13:04 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	convert_specifier(t_printf *data)
{
	data->i++;
	get_flags(data);
	get_width(data);
	get_precision(data);
	get_length(data);
	get_conversion_type(data);
	/* 
	if (data->conversion == 'u')
		convert_u(data);
	if (data->conversion == 'o')
		convert_o(data);
	if (data->conversion == 'f')
		convert_f(data);
	*/
	if (data->conversion == 'c')
		convert_c(data);
	if (data->conversion == 's' || data->conversion == 'S')
		convert_s(data);
	if (data->conversion == 'p')
		convert_p(data);
	if (data->conversion == 'x' || data->conversion == 'X')
		convert_x(data);
	if (data->conversion == 'd' || data->conversion == 'i')
		convert_i(data);
	if (data->conversion == '%')
		convert_percent(data);
}