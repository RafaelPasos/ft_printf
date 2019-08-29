# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpasos <rpasos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 19:58:06 by apasos-g          #+#    #+#              #
#    Updated: 2019/08/26 04:01:26 by rpasos           ###   ########.fr        #
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

LIBFT = *.c\

CONVERSIONS = convert_c.c\
			convert_s.c\
			convert_p.c\
			convert_percent.c\
			convert_x.c\
			convert_i.c\

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
