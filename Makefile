SRCS		= src/main.c \
			  src/utils/img.c \
			  src/utils/map.c \
			  src/utils/convert.c
HEADERS		= src/includes/fdf.h \
			  src/includes/img.h \
			  src/includes/map.h
OBJS		= ${SRCS:.c=.o}
NAME		= fdf
CC			= clang -g
FLAGS		= -lm -Lmlx -lmlx -Llibft -lft
FLAGS_MACOS	= -framework OpenGL -framework AppKit
FLAGS_LINUX	= -lXext -lX11

%.o: %.c ${HEADERS}
			${CC} -Isrc/includes -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${HEADERS}
			make -C libft
			make -C mlx
			${CC} ${FLAGS} ${FLAGS_MACOS} -o $@ ${OBJS}

linux:		${OBJS} ${HEADERS}
			make -C libft
			make -C mlx
			${CC} ${OBJS} ${FLAGS} ${FLAGS_LINUX} -o ${NAME}

clean:
			make clean -C libft
			make clean -C mlx
			rm -rf ${OBJS}

fclean:		clean
			make fclean -C libft
			make fclean -C mlx
			rm -rf ${NAME}
