SRCS		= src/main.c \
			  src/utils/img.c

OBJS		= ${SRCS:.c=.o}
NAME		= fdf
CC			= gcc -g
FLAGS		= -Lmlx -lmlx -lm -framework OpenGL -framework AppKit

%.o: %.c src/includes/img.h
			${CC} -Isrc/includes -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o $@ ${OBJS}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}
