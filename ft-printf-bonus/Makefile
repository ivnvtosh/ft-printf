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

NAME	=	libftprintfbonuspart.a
HEADER	=	printf_bonus.h

LIBFT	=	../libft/libft.a

SRCS	=	print_char_bonus.c						\
			print_decimal_bonus.c					\
			print_hexadecimal_lowercase_bonus.c		\
			print_hexadecimal_uppercase_bonus.c		\
			print_number_bonus.c					\
			print_part_bonus.c						\
			print_pointer_bonus.c					\
			print_string_bonus.c					\
			print_unsigned_decimal_bonus.c			\
			printf_utils_bonus.c					\
			print_space_bonus.c						\
			ft_printf_bonus.c

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
OPTION	=	-c -I $(HEADER)
RM		=	rm -f

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT)
			cp $(LIBFT) $(NAME) 
			ar crs $(NAME) $(OBJS)

%.o		:	%.c $(HEADER)
			$(CC) -o $(FLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
