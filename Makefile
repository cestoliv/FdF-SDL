SRCS		= src/main.c \
			  src/utils/img.c \
			  src/utils/map.c \
			  src/utils/convert.c
HEADERS		= src/includes/fdf.h \
			  src/includes/img.h \
			  src/includes/map.h
OBJS		= ${SRCS:.c=.o}
NAME		= fdf
CC			= gcc -g
FLAGS		= -lm -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit

%.o: %.c ${HEADERS}
			${CC} -Isrc/includes -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${HEADERS}
			make -C libft
			${CC} ${FLAGS} -o $@ ${OBJS}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}
