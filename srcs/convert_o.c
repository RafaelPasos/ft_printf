/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:30:33 by apasos-g          #+#    #+#             */
/*   Updated: 2019/09/08 22:34:23 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

unsigned long long	get_num_o(t_printf *data)
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

char				*make_octal_num(unsigned long long number)
{
    char	*stroct;
	char	octchar;
    int		remainder;

	stroct = NULL;
	if (number == 0)
		return (ft_strdup("0"));
    if (number)
    {
		stroct = ft_strdup("");
        while (number)
        {
            remainder = number % 8;
			octchar = remainder + '0';
			stroct = concat_hex(stroct, octchar);
			number /= 8;
        }
		ft_strrev(stroct);
    }
    return (stroct);
}

int	precision_oct(t_printf *data, char	*stroct, size_t	*strlena)
{
	if (ft_strcmp(stroct, "0") == 0 && data->precision == 0)
	{
		free(stroct);
		*strlena = 0;
		stroct = ft_strdup("");
		return 0;
	}
	if (data->flag[HASHFLAG] == '#')
	{ 
		return (1);
	}
	return 0;
}

void				convert_o(t_printf *data)
{
	unsigned long long	number;
	char				*stroct;
	char				char_pad;
	size_t				strlena;

	char_pad = (data->flag[ZEROFLAG] == '0' && data->flag[MINUSFLAG] != '-') ? '0' : ' ';
	number = get_num_o(data);
	stroct = make_octal_num(number);
	strlena = ft_strlen(stroct);
	if (precision_hex(data, stroct, &strlena))
		strlena++;
	if (char_pad == ' ' && data->flag[MINUSFLAG] != '-')
		padding(data, char_pad, data->field_width - strlena);
	if (data->flag[HASHFLAG] == '#' && number != 0)
	{
		write(1, "0", 1);
		data->len++;
	}
	if (char_pad != ' ' && data->flag[MINUSFLAG] != '-')
		padding(data, char_pad, data->field_width - strlena);
	//if (data->flag[MINUSFLAG] != '-')
	//	padding(data, char_pad, data->field_width - strlena);
	if (ft_strcmp(stroct, "") != 0 || data->precision != 0)
		ft_putstr(stroct);
	if (data->flag[MINUSFLAG] == '-')
		padding(data, char_pad, data->field_width - strlena);
	data->len += ft_strlen(stroct);
	free(stroct);
}