/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 03:16:04 by apasos-g          #+#    #+#             */
/*   Updated: 2019/09/08 04:34:03 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

long double	get_num_f(t_printf *data)
{
	long double		num;

	if (ft_strcmp(data->length, "L") == 0)
		num = va_arg(data->args, long double);
	else
	{
		num = va_arg(data->args, double);
		return ((double)num);
	}
	return (num);
}

void		dispatch_padding_f(t_printf *data, long double num)
{
	char	char_pad;

	char_pad = (data->flag[ZEROFLAG] == '0' && data->flag[MINUSFLAG] != '-') ? '0' : ' ';
	padding(data, char_pad, num);
}


void		put_sign_f(t_printf *data, long double num)
{
	if (num < 0)
		return ;
	if (data->flag[PLUSFLAG] == '+')
	{
		write(1, "+", 1);
		data->len++;
		return ;
	}
	if (data->flag[SPACEFLAG] == ' ')
	{
		write(1, " ", 1);
		data->len++;
		return ;
	}
	return ;
}

void			put_float(t_printf *data, long double number)
{
	long double		num;
	long long		whole;

	num = (number < 0) ? -number : number;
	whole = (long long)num;
	if (num - whole >= 0.5 && data->precision == 0)
		whole += 1;
	num -= whole;
	ft_putnbr(whole);
	if (data->precision <= 15)
		num += 0.0000000000000001;
	if (data->precision > 0 || data->flag[4] == '#')
		ft_putchar('.');
	if (data->precision != 0)
		while (data->precision)
		{
			num *= 10;
			whole = (unsigned long long)num;
			num -= whole;
			whole %= 10;
			ft_putchar(whole + '0');
			data->precision--;
		}
}

int			ft_numlen(unsigned long long num)
{
	int		i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

int			get_width_f(t_printf *data, long double num, int count)
{
	int		len;

	len = count + (((num < 0) || data->flag[1] == '+'
						|| data->flag[2] == ' ') ? 1 : 0);
	return ((data->field_width > len) ? data->field_width - len : 0);
}

int			get_len_f(t_printf *data, long double num)
{
	int					len;
	unsigned long long	whole;

	len = 0;
	num = (num < 0) ? -num : num;
	whole = (unsigned long long)num;
	len += ft_numlen(num);
	len += (data->precision > 0 || data->flag[4] == '#') ? 1 : 0;
	len += data->precision;
	return (len);
}

void		convert_f(t_printf *data)
{
	long double	num;
    int         count;
    int         width;

	num = get_num_f(data);
    data->precision = data->precision == -1 ? 6 : data->precision;
    count = get_len_f(data, num);
	width = get_width_f(data, num, count);
	if (data->field_width > count + width && (!(data->flag[MINUSFLAG] == '-')))
		dispatch_padding_f(data, num);
	put_sign_f(data, num);
	put_float(data, num);
    data->len = data->len + count;
	if (data->field_width > count + width && data->flag[MINUSFLAG] == '-')
		dispatch_padding_f(data, num);
	//free(newstr);
}