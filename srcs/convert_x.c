/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 04:06:10 by rpasos            #+#    #+#             */
/*   Updated: 2019/09/08 21:35:11 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

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

char				*make_hex_num(t_printf *data)
{
    char	*strhex;
	char	hexchar;
    int		remainder;
	char	*hex_string_temp;
	unsigned long long number;

	number = get_num_x(data);
	strhex = NULL;
	if (number == 0)
		return (ft_strdup("0"));
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
	check_uppercase_str(data, strhex);
    return (strhex);
}

int	precision_hex(t_printf *data, char	*strhex, size_t	*strlena)
{
	if (ft_strcmp(strhex, "0") == 0 && data->precision == 0)
	{
		free(strhex);
		*strlena = 0;
		strhex = ft_strdup("");
		return 0;
	}
	if (data->flag[HASHFLAG] == '#')
	{ 
		return (1);
	}
	return 0;
}

void				convert_x(t_printf *data)
{
	char				*strhex;
	char				char_pad;
	size_t				strlena;

	char_pad = (data->flag[3] == '0' && data->flag[0] != '-') ? '0' : ' ';
	strhex = make_hex_num(data);
	strlena = ft_strlen(strhex);
	if (precision_hex(data, strhex, &strlena))
		strlena +=2;
	if (char_pad != ' ' && data->flag[HASHFLAG] == '#' &&	\
			(data->precision != 0 || ft_strcmp(strhex, "") != 0))
	{
		if (ft_strcmp(strhex, "0") != 0)
		{
			if (data->conversion == 'x')
				write(1, "0x", 2);
			else
				write(1, "0X", 2);
			data->len += 2;
		}
	}
	if (data->flag[MINUSFLAG] != '-')
		padding(data, char_pad, data->field_width - strlena);
	if (char_pad == ' ' && data->flag[HASHFLAG] == '#' &&	\
			(data->precision != 0 || ft_strcmp(strhex, "") != 0))
	{
		if (ft_strcmp(strhex, "0") != 0)
		{
			if (data->conversion == 'x')
				write(1, "0x", 2);
			else
				write(1, "0X", 2);
			data->len += 2;
		}
	}
	if (ft_strcmp(strhex, "") != 0 || data->precision != 0)
	{
		ft_putstr(strhex);
	}
	if (data->flag[MINUSFLAG] == '-')
		padding(data, char_pad, data->field_width - strlena);
	data->len += ft_strlen(strhex);
	free(strhex);
}