SOURCES =	so_long.c 			\
			so_long_parsing.c	\
			so_long_parsing_2.c	\
			so_long_parsing_3.c	\
			so_long_error.c		\
			so_long_error_2.c	\
			so_long_dev.c		\
			so_long_utils.c		\
			so_long_moves.c		\
			so_long_moves_2.c	\
			so_long_texture.c	\
			so_long_key.c		\
			so_long_key_2.c		\

OBJS	=	${SOURCES:%.c=${OBJDIR}%.o}

HEADER	=	so_long.h

LIB = libft/libft.a

LIB2 = get_next_line/gnl.a

LIB3 = minilibx-linux/libmlx.a

LIB4 = minilibx-linux/libmlx_Linux.a

NAME	=	so_long

CC	=	cc

MLX_FLAG	=	-Lminilibx-linux -lmlx -lX11 -lXext

FLAGS	=	-g3 -Wall -Wextra -Werror

OBJDIR	= OBJS/

all	:	libmlx ${NAME}

${OBJDIR}%.o	:	%.c ${HEADER}
	mkdir -p ${OBJDIR}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} ${LIB}	${LIB2}	Makefile
	${CC} ${MLX_FLAG} ${FLAGS}  -o $@ ${OBJS} ${LIB} ${LIB2} ${LIB3} ${LIB4}

libmlx	:
	$(MAKE) -C minilibx-linux

${LIB} : FORCE
	make bonus -C libft/

${LIB2} : FORCE
	make -C get_next_line/

FORCE:

clean	:
	rm -rf ${OBJDIR}
	make fclean -C libft/
	make -C minilibx-linux clean
	make fclean -C get_next_line/

fclean	:	clean
	rm -f ${NAME}
	make -C minilibx-linux clean
	make fclean -C libft/
	make fclean -C get_next_line/

re	:	fclean all

.PHONY	:	all clean fclean re bonus libmlx FORCE