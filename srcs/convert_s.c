/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 20:16:48 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/25 20:05:44 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_uppercase_str(t_printf *data, char *str)
{
    int		i;

	i = 0;
	if (data->conversion == 'S' || data->conversion == 'X')
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
}

void			convert_s(t_printf *data)
{
	char	*str;

	str = va_arg(data->args, char *);
	if (str)
	{
		if (data->precision != -1)
			str = ft_strndup(str, data->precision);
		else
			str = ft_strdup(str);
	}
	else
	{
		if (data->precision != -1)
			str = ft_strdup("");
		else
			str = ft_strdup("(null)");
	}
	data->len += ft_strlen(str);
	if (data->flag[0] != '-')
		padding(data, ' ', data->field_width - ft_strlen(str));
	check_uppercase_str(data, str);
	ft_putstr(str);
	if (data->flag[0] == '-')
		padding(data, ' ', data->field_width - ft_strlen(str));
	free(str);
}