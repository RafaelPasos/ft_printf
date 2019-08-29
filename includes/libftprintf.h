/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 00:25:00 by apasos-g          #+#    #+#             */
/*   Updated: 2019/08/26 04:12:36 by rpasos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct	s_printf
{
	va_list		args;
	char		*formatstring;
	int			i;
	int			len;
	char		flag[5];
	char		length[3];
	char		conversion;
	int			field_width;
	int			precision;
	char		*flag_mask;
	char		*length_mask;
	char		*conversion_mask;
}				t_printf;

int					ft_printf(const char *format, ...);
void				print_it(t_printf *data);
void				print_normalstr(t_printf *data, int ordinary_chars);
void				reset(t_printf *data);
void				initialize(t_printf *data, const char *format);
void				convert_specifier(t_printf *data);
void				get_conversion_type(t_printf *data);
void				get_length(t_printf *data);
void				get_precision(t_printf *data);
void				get_width(t_printf *data);
void				get_flags(t_printf *data);
//void				convert_o(t_printf *data);
//void				convert_f(t_printf *data);
//void				convert_u(t_printf *data);
void				convert_i(t_printf *data);
void				convert_c(t_printf *data);
void				convert_s(t_printf *data);
void				check_uppercase_str(t_printf *data, char *str);
void				convert_p(t_printf *data);
char				*make_hex(intptr_t pointer);
char				*concat_hex(char *strhex, char src);
char				*ft_strrev(char *str);
void				convert_percent(t_printf *data);
void				convert_x(t_printf *data);
char				*make_hex_num(unsigned long long number);
unsigned long long	get_num_x(t_printf *data);
long long			get_num_i(t_printf *data);
void				padding(t_printf *data, char c, int len);
char				*ft_lltoa(long long nbr);
char				*ft_lltoanegative(long long nbr);
char				*ft_lltoapositive(long long nbr);
void				dispatch_padding_i(t_printf *data, long long num, char *numpre);

#endif