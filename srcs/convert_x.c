/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 04:06:10 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/26 04:02:38 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

unsigned long long	get_num_x(t_printf *data)
{
	unsigned long long	num;

	if (ft_strcmp(data->length, "hh") == 0)
		num = (unsigned char)(va_arg(data->args, unsigned int));
	else if (ft_strcmp(data->length, "h") == 0)
		num = (unsigned short)(va_arg(data->args, unsigned int));
	else if (ft_strcmp(data->length, "ll") == 0)
		num = (unsigned long long)(va_arg(data->args, unsigned long long));
	else if (ft_strcmp(data->length, "l") == 0)
		num = (unsigned long)(va_arg(data->args, unsigned long));
	else
		num = (unsigned int)(va_arg(data->args, unsigned int));
	return (num);
}

char				*make_hex_num(unsigned long long number)
{
    char	*strhex;
	char	hexchar;
    int		remainder;
	char	*hex_string_temp;

	strhex = NULL;
	hex_string_temp = "0123456789abcdef";
    if (number)
    {
		strhex = ft_strdup("");
        while (number)
        {
            remainder = number % 16;
			hexchar = hex_string_temp[remainder];
			strhex = concat_hex(strhex, hexchar);
			number /= 16;
        }
		ft_strrev(strhex);
    }
    return (strhex);
}

void				convert_x(t_printf *data)
{
	unsigned long long	number;
	char				*strhex;
	char				char_pad;

	char_pad = (data->flag[3] == '0' && data->flag[0] != '-') ? '0' : ' ';
	number = get_num_x(data);
	strhex = make_hex_num(number);
	check_uppercase_str(data, strhex);
	if (data->flag[0] != '-')
		padding(data, char_pad, data->field_width - ft_strlen(strhex));
	ft_putstr(strhex);
	if (data->flag[0] == '-')
		padding(data, char_pad, data->field_width - ft_strlen(strhex));
	data->len += ft_strlen(strhex);
	free(strhex);
}