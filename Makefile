SOURCES =	so_long.c 			\
			so_long_parsing.c	\
			so_long_error.c		\
			so_long_dev.c		\

OBJS	=	${SOURCES:%.c=${OBJDIR}%.o}

HEADER	=	so_long.h

LIB = libft/libft.a

LIB2 = get_next_line/gnl.a

NAME	=	so_long

CC	=	cc

FLAGS	=	-g3 #-Wall -Wextra -Werror

OBJDIR	= OBJS/

all	:	${NAME}

${OBJDIR}%.o	:	%.c ${HEADER}
	mkdir -p ${OBJDIR}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} ${LIB}	${LIB2}	Makefile
	cp libft/libft.a libft.a
	cp get_next_line/gnl.a gnl.a
	${CC} ${FLAGS}  -o $@ ${OBJS} ${LIB} ${LIB2}


${LIB} : FORCE
	make bonus -C libft/

${LIB2} : FORCE
	make -C get_next_line/

FORCE:

clean	:
	rm -rf ${OBJDIR}
	make fclean -C libft/
	make fclean -C get_next_line/

fclean	:	clean
	rm -f ${NAME}
	rm libft.a
	rm gnl.a
	make fclean -C libft/
	make fclean -C get_next_line/

re	:	fclean all

.PHONY	:	all clean fclean re bonus FORCE