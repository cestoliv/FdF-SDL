FRAMERATE	=	60
SRCS		=	src/utils/controls_utils.c \
				src/utils/controls.c \
				src/utils/convert_utils.c \
				src/utils/convert.c \
				src/utils/draw.c \
				src/utils/instructions.c \
				src/utils/map.c \
				src/utils/matrix.c \
				src/utils/rotation_matrix.c \
				src/utils/utils.c \
				src/main.c
HEADERS		= 	src/includes/fdf.h \
				src/includes/keys.h
NAME		=	fdf
CC			=	clang -g
FLAGS		=	-lm -Llibft -lft `sdl2-config --libs` -lSDL2_ttf

%.o: %.c ${HEADERS}
			${CC} -D FRAMERATE=${FRAMERATE} $< -c -o $@ `sdl2-config --cflags`

all:		${NAME}

${NAME}:	${SRCS:.c=.o} ${HEADERS}
			make -C libft
			${CC} ${SRCS:.c=.o} -o ${NAME} ${FLAGS}

clean:
			rm -rf ${SRCS:.c=.o}
			make clean -C libft

fclean:		clean
			rm -rf ${NAME}
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re
