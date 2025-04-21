NAME = libft.a

SOURCES = 	get_next_line.c			\
			get_next_line_utils.c	\

OBJS	=	${SOURCES:.c=.o}

HEADER	=	get_next_line.h

NAME	=	gnl.a

CC	=	cc

AR	=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all	:	${NAME}

%.o	:	%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} Makefile
	${AR} ${NAME} ${OBJS}

clean	:
	rm -f ${OBJS} ${B_OBJS}

fclean	:	clean
	rm -f ${NAME} ${B_OBJS}

re	:	fclean all

.PHONY	:	all clean fclean re bonus