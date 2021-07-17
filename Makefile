
.PHONY: all clean fclean re

NAME = client
NAME2 = server

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./libft/

SRCS = 	client.c
SRCS2 = server.c
OBJS = ${SRCS:.c=.o}
OBJS2 = ${SRCS2:.c=.o}
all: ${NAME} ${NAME2}

debug: CFLAGS += -fsanitize=address -g
debug: fclean all;

dvs: CFLAGS += -g
dvs: fclean all;

tools:
	make -C ./libft/

$(NAME) :${OBJS} | tools
		${CC} ${CFLAGS} ${OBJS} -lft ./libft/libft.a -L ./libft/ -o ${NAME}

$(NAME2) :${OBJS2}
		${CC} ${CFLAGS} ${OBJS2} -lft ./libft/libft.a -L ./libft/ -o ${NAME2}

clean:
		rm -f ${OBJS} ${OBJS2}
		make -C ./libft/ clean

fclean:	clean
		rm -f ${NAME} ${NAME2}
		make -C ./libft/ fclean

re: fclean all
