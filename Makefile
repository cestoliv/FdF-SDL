SRCS		=	src/utils/controls_utils.c \
				src/utils/controls.c \
				src/utils/convert_utils.c \
				src/utils/convert.c \
				src/utils/draw.c \
				src/utils/img.c \
				src/utils/instructions.c \
				src/utils/map.c \
				src/utils/matrix.c \
				src/utils/rotation_matrix.c \
				src/utils/utils.c \
				src/main.c
HEADERS		=	src/includes/fdf.h \
				src/includes/keys_linux.h \
				src/includes/keys_mac.h
OBJS		=	${SRCS:.c=.o}
NAME		=	fdf
CC			=	clang -Wall -Wextra -Werror
FLAGS		=	-lm -Lmlx -lmlx -Llibft -lft
FLAGS_MACOS	=	-framework OpenGL -framework AppKit
FLAGS_LINUX	=	-lXext -lX11

%.o: %.c ${HEADERS}
			${CC} -Isrc/includes -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${HEADERS}
			make -C libft
			make -C mlx
			cp mlx/libmlx.dylib .
			${CC} ${FLAGS} ${FLAGS_MACOS} -o $@ ${OBJS}

linux:		${OBJS} ${HEADERS}
			make -C libft
			make -C mlx
			${CC} ${OBJS} ${FLAGS} ${FLAGS_LINUX} -o ${NAME}

clean:
			make clean -C libft
			make clean -C mlx
			rm -rf ${OBJS}
			rm libmlx.dylib

fclean:		clean
			make fclean -C libft
			make clean -C mlx
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re ${NAME} linux
