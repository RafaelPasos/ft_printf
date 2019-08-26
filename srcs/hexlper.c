/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexlper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 01:46:33 by rpasos            #+#    #+#             */
/*   Updated: 2019/08/25 20:04:13 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < --len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
	}
	return (str);
}

char	*concat_hex(char *strhex, char src)
{
	char	*newstrhex;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(strhex);
	newstrhex = ft_strnew(len + 1);
	while (i < len)
	{
		newstrhex[i] = strhex[i];
		i++;
	}
	newstrhex[i] = src;
	free(strhex);
	return (newstrhex);
}

char	*make_hex(intptr_t pointer)
{
    char	*strhex;
	char	hexchar;
    int		remainder;
	char	*hex_string_temp;

	strhex = NULL;
	hex_string_temp = "0123456789abcdef";
    if (pointer)
    {
		strhex = ft_strdup("");
        while (pointer)
        {
            remainder = pointer % 16;
			hexchar = hex_string_temp[remainder];
			strhex = concat_hex(strhex, hexchar);
			pointer /= 16;
        }
		ft_strrev(strhex);
    }
    return (strhex);
}