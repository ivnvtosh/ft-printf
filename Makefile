NAME	=	libftprintf.a
SRCS	=	$(wildcard *.c)

CC = gcc

HEADER = ft_printf.h
OBJS		= 	${SRCS:%.c=%.o}

CFLAGS	=	-Wall -Wextra -Werror 

.PHONY	:	all clean fclean re 

all		:	$(NAME) 

$(NAME)	:	$(OBJS) ${HEADER}
	ar -rcs $(NAME) $?

%.o		:	%.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f  $(NAME)

re		:	fclean all
