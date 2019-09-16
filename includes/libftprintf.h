/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 00:25:00 by apasos-g          #+#    #+#             */
/*   Updated: 2019/09/08 22:09:53 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>

# define MINUSFLAG 0
# define PLUSFLAG 1
# define SPACEFLAG 2
# define ZEROFLAG 3
# define HASHFLAG 4
# define APASOS_G_LONGLONGMAX ~0uL >> 1
# define APASOS_G_LONGLONGMIN ~0uL << ((sizeof(long long) * 8) - 1)

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
	int			num_positive;
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
void				convert_o(t_printf *data);
unsigned long long	get_num_o(t_printf *data);
char				*make_octal_num(unsigned long long number);
void				convert_f(t_printf *data);
void				convert_u(t_printf *data);
void				convert_i(t_printf *data);
void				put_sign_u(t_printf *data);
char    			*transform_num_u(t_printf *data, unsigned long long num);
char				*precision_padder_leadchar_u(t_printf *data, int presover, char *strnum);
char				*precision_padder_u(int presover, char *strnum);
void				put_sign_i(t_printf *data);
char    			*transform_num(t_printf *data, long long num);
char				*peel_negative_sign_str(char *num);
char				*precision_padder_leadchar(t_printf *data, int presover, char *strnum);
char				*precision_padder(int presover, char *strnum);
void				convert_c(t_printf *data);
void				convert_s(t_printf *data);
void				check_uppercase_str(t_printf *data, char *str);
void				convert_p(t_printf *data);
char				*make_hex(intptr_t pointer);
char				*concat_hex(char *strhex, char src);
char				*ft_strrev(char *str);
void				convert_percent(t_printf *data);
void				convert_x(t_printf *data);
char				*make_hex_num(t_printf *data);
unsigned long long	get_num_x(t_printf *data);
long long			get_num_i(t_printf *data);
unsigned long long	get_num_u(t_printf *data);
void				padding(t_printf *data, char c, int len);
char				*ft_ulltoa(unsigned long long nbr);
char				*ft_lltoa(long long nbr);
char				*ft_lltoanegative(long long nbr);
char				*ft_lltoapositive(long long nbr);
void				dispatch_padding_i(t_printf *data, long long num, char *strnum);
void				dispatch_padding_u(t_printf *data, char *strnum);
void				dispatch_padding(t_printf *data, long long num, char *strnum);
int					get_len_f(t_printf *data, long double num);
int					get_width_f(t_printf *data, long double num, int count);
int					ft_numlen(unsigned long long num);
void				put_float(t_printf *data, long double number);
void				put_sign_f(t_printf *data, long double num);
void				dispatch_padding_f(t_printf *data, long double num);
int					precision_hex(t_printf *data, char	*strhex, size_t	*strlena);
int					precision_oct(t_printf *data, char	*stroct, size_t	*strlena);

#endif