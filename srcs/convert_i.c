/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 00:19:18 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/26 05:58:19 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

long long	get_num_i(t_printf *data)
{
	long long	num;

	if (ft_strcmp(data->length, "hh") == 0)
		num = (signed char)(va_arg(data->args, int));
	else if (ft_strcmp(data->length, "h") == 0)
		num = (short)(va_arg(data->args, int));
	else if (ft_strcmp(data->length, "ll") == 0)
		num = (long long)(va_arg(data->args, long long));
	else if (ft_strcmp(data->length, "l") == 0)
		num = (long)(va_arg(data->args, long));
	else
		num = (va_arg(data->args, int));
	return (num);
}

void		dispatch_padding_i(t_printf *data, long long num, char *numpre)
{
	char		char_pad;
	char		char_lead;

	char_pad = (data->flag[3] == '0' && data->flag[0] != '-') ? '0' : ' ';
	char_lead = 'n';
	if (data->flag[2] == ' ')
		char_lead = ' ';
	if (data->flag[1] == '+')
		char_lead = '+';
	if (char_lead != 'n')
	{
		if (num >= 0)
		{
			write(1, &char_lead, 1);
			data->len++;
			padding(data, char_pad, data->field_width - ft_strlen(numpre) - 1);
		}
		else
			padding(data, char_pad, data->field_width - ft_strlen(numpre));
	}
	else
		padding(data, char_pad, data->field_width - ft_strlen(numpre));
}

char	*fix_precision_i(int presover, long long num, char *strnum)
{
	char	*newstr;
	int		finalsize;
	int		i;
	int		j;

	finalsize = ft_strlen(strnum) + presover;
	//if (num < 0)
	//	finalsize++;
	newstr = ft_strnew(finalsize);
	i = 0;
	while (i < presover)
	{
		newstr[i] = '0';
		i++;
	}
	j = 0;
	if (num < 0)
		j++;
	while (j < (int)ft_strlen(strnum))
	{
		newstr[i + j] = strnum[j];
		j++;
	}
	if (num < 0)
		newstr[0] = '-';
	return (newstr);
}

void		convert_i(t_printf *data)
{
	long long	num;
	char		*strnum;
	char		*newstr;

	num = get_num_i(data);
	strnum = ft_lltoa(num);
	newstr = strnum;
	if (data->precision > (int)ft_strlen(strnum))
	{
		newstr = fix_precision_i(data->precision - ft_strlen(strnum), num, strnum);
		free(strnum);
	}
	if (data->flag[0] != '-')
		dispatch_padding_i(data, num, newstr);
	if (ft_strcmp(newstr, "0") != 0 || data->precision != 0)
	{
		ft_putstr(newstr);
		data->len += ft_strlen(newstr);
	}
	if (data->flag[0] == '-')
		dispatch_padding_i(data, num, newstr);
	free(newstr);
}