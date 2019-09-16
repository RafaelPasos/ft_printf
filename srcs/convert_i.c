/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:52:13 by apasos-g          #+#    #+#             */
/*   Updated: 2019/09/08 04:53:19 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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

void		dispatch_padding_i(t_printf *data, long long num, char *strnum)
{
	char	char_pad;

	char_pad = (data->flag[ZEROFLAG] == '0' && data->flag[MINUSFLAG] != '-') ? '0' : ' ';
	if (data->precision != -1)
	{
		padding(data, ' ', data->field_width - ft_strlen(strnum));
	}
	else
	{
		if (data->flag[ZEROFLAG] == '0' && num < 0)
		{
			write(1, "-", 1);
			padding(data, char_pad, data->field_width - ft_strlen(strnum) - 1);
			data->len++;
		}
		else
		{
			if (num > 0 && (data->flag[PLUSFLAG] == '+' || data->flag[SPACEFLAG] == ' '))
				padding(data, char_pad, data->field_width - ft_strlen(strnum) - 1);
			else
				if (num < 0)
					padding(data, char_pad, data->field_width - ft_strlen(strnum) - 1);
				else
					padding(data, char_pad, data->field_width - ft_strlen(strnum));		
		}
	}
}

char	*precision_padder(int presover, char *strnum)
{
	int		i;
	char	*newstr;

	newstr = ft_strnew(ft_strlen(strnum) + presover);
	i = 0;
	while (i < (int) ft_strlen(strnum) + presover)
	{
		if (i < presover)
			newstr[i] = '0';
		else
			newstr[i] = strnum[i - presover];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*precision_padder_leadchar(t_printf *data, int presover, char *strnum)
{
	int		i;
	char	lead;
	char	*newstr;

	lead = '.';
	if (data->flag[SPACEFLAG])
		lead = ' ';
	if (data->flag[PLUSFLAG])
		lead = '+';
	if (data->num_positive == 0)
		lead = '-';
	newstr = ft_strnew(ft_strlen(strnum) + presover + 1);
	i = 1;
	while (i < (int)ft_strlen(strnum) + presover + 1)
	{
		if (i < presover + 1)
			newstr[i] = '0';
		else
			newstr[i] = strnum[i - presover];
		i++;
	}
	newstr[0] = lead;
	newstr[i] = '\0';
	return (newstr);
}

char	*peel_negative_sign_str(char *num)
{
	char	*oolk;

	oolk = num + 1;
	return (oolk);
}

char    *transform_num(t_printf *data, long long num)
{
    char    *str;
	char	*tmpstr;

    if (num == 0 && data->precision == 0)
        return (ft_strdup(""));
    str = ft_lltoa(num);
	if (num < 0)
	{
		data->num_positive = 0;
		tmpstr = str;
		str = peel_negative_sign_str(str);
		free(tmpstr);
	}
	return str;
}

void		put_sign_i(t_printf *data)
{
	if (data->precision != -1)
		return ;
	if (data->num_positive != 1)
	{
		if (data->flag[ZEROFLAG] == '0')
			return ;
		write(1, "-", 1);
		data->len++;
		return ;
	}
	else
	{
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
	}
	return ;
}

void		convert_i(t_printf *data)
{
	long long	num;
	char		*strnum;
	char		*newstr;

	num = get_num_i(data);
	strnum = transform_num(data, num);
	newstr = strnum;
	if (data->precision > (int)ft_strlen(strnum))
	{
		if (data->num_positive && (!(data->flag[SPACEFLAG] == ' ')) \
								&& (!(data->flag[PLUSFLAG] == '+')))
			newstr = precision_padder(data->precision - ft_strlen(strnum), strnum);
		else
			newstr = precision_padder_leadchar(data, data->precision - ft_strlen(strnum), strnum);
		free(strnum);
	}
	if (data->field_width > (int)ft_strlen(newstr) && (!(data->flag[MINUSFLAG] == '-')))
		dispatch_padding_i(data, num, newstr);
	put_sign_i(data);
	ft_putstr(newstr);
	data->len += ft_strlen(newstr);
	if (data->field_width > (int)ft_strlen(newstr) && data->flag[MINUSFLAG] == '-')
		dispatch_padding_i(data, num, newstr);
	//free(newstr);
}