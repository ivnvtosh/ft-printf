# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 15:45:41 by ccamie            #+#    #+#              #
#    Updated: 2021/10/18 15:45:43 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
HEADER	=	ft_printf.h
LIBFT	=	libft/libft.a

SRCS	=	format_specifier/print_char.c					\
			format_specifier/print_decimal.c				\
			format_specifier/print_hexadecimal_lowercase.c	\
			format_specifier/print_hexadecimal_uppercase.c	\
			format_specifier/print_pointer.c				\
			format_specifier/print_string.c					\
			format_specifier/print_unsigned_decimal.c		\
			ft_printf.c										\
			printf-option.c									\
			printf-utils.c

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
OPTION	=	-c -I $(HEADER)
RM		=	rm -f

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT)
			cp $(LIBFT) $(NAME) 
			ar crs $(NAME) $(OBJS)

$(LIBFT):
			make -C libft

%.o		:	%.c $(HEADER)
			$(CC) -o $(FLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
