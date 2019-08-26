/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 03:21:09 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/25 20:04:08 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
 
void	padding(t_printf *data, char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, &c, 1);
        i++;
		data->len++;
	}
}