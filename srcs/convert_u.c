/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:30:34 by apasos-g          #+#    #+#             */
/*   Updated: 2019/09/08 01:04:03 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

unsigned long long	get_num_u(t_printf *data)
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

void		dispatch_padding_u(t_printf *data, char *strnum)
{
	char	char_pad;

	char_pad = (data->flag[ZEROFLAG] == '0' && data->flag[MINUSFLAG] != '-') ? '0' : ' ';
	if (data->precision != -1)
	{
		padding(data, ' ', data->field_width - ft_strlen(strnum));
	}
	else
	{
		if (data->flag[PLUSFLAG] == '+' || data->flag[SPACEFLAG] == ' ')
			padding(data, char_pad, data->field_width - ft_strlen(strnum) - 1);
		else
			padding(data, char_pad, data->field_width - ft_strlen(strnum));	
	}
}


char	*precision_padder_u(int presover, char *strnum)
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

char	*precision_padder_leadchar_u(t_printf *data, int presover, char *strnum)
{
	int		i;
	char	lead;
	char	*newstr;

	lead = '.';
	if (data->flag[SPACEFLAG])
		lead = ' ';
	if (data->flag[PLUSFLAG])
		lead = '+';
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

void		put_sign_u(t_printf *data)
{
	if (data->precision != -1)
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

char    *transform_num_u(t_printf *data, unsigned long long num)
{
    char    *str;

    if (num == 0 && data->precision == 0)
        return (ft_strdup(""));
    str = ft_ulltoa(num);
	return str;
}

void		convert_u(t_printf *data)
{
	unsigned long long	num;
	char		    *strnum;
	char		    *newstr;

	num = get_num_u(data);
	strnum = transform_num_u(data, num);
	newstr = strnum;
	if (data->precision > (int)ft_strlen(strnum))
	{
		if ((!(data->flag[SPACEFLAG] == ' ')) \
								&& (!(data->flag[PLUSFLAG] == '+')))
			newstr = precision_padder_u(data->precision - ft_strlen(strnum), strnum);
		else
			newstr = precision_padder_leadchar_u(data, data->precision - ft_strlen(strnum), strnum);
		free(strnum);
	}
	if (data->field_width > (int)ft_strlen(newstr) && (!(data->flag[MINUSFLAG] == '-')))
		dispatch_padding_u(data, newstr);
	put_sign_u(data);
	ft_putstr(newstr);
	data->len += ft_strlen(newstr);
	if (data->field_width > (int)ft_strlen(newstr) && data->flag[MINUSFLAG] == '-')
		dispatch_padding_u(data, newstr);
	//free(newstr);
}