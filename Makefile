# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apasos-g <apasos-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 19:58:06 by apasos-g          #+#    #+#              #
#    Updated: 2019/09/08 04:53:57 by apasos-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c\
		convert_specifier.c\
		get_conversion_type.c\
		get_flags.c\
        get_length.c\
		get_width.c\
		get_precision.c\
		get_width.c\
        initialize.c\
		padding.c\
		hexlper.c\
		print_normalstr.c\
		lltoa.c\
		ulltoa.c\

LIBFT = *.c\

CONVERSIONS = convert_c.c\
			convert_s.c\
			convert_p.c\
			convert_percent.c\
			convert_x.c\
			convert_i.c\
			convert_o.c\
			convert_u.c\
			convert_f.c\

INCLUDES = includes/

FLAGS = -Wall -Werror -Wextra

OBJECTS = $(patsubst %.c,%.o,$(SRCS))
OBJECTS += $(patsubst %.c,%.o,$(CONVERSIONS))
OBJECTS += $(patsubst %.c,%.o,$(LIBFT))

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(addprefix srcs/,$(SRCS)) $(addprefix libft/,$(LIBFT)) $(addprefix srcs/,$(CONVERSIONS)) -I $(INCLUDES)
	ar -rcs $(NAME) $(OBJECTS)
	rm -f $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
