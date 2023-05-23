NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address


SRCS =  ./srcs/so_long.c\
		./srcs/checker.c\
		./srcs/errorhandler.c\
		./srcs/wineed.c\
		./srcs/init.c \
		./srcs/readmap.c \
		./srcs/gnl.c \
		./srcs/gnl_utils.c \
		./srcs/mapchecker.c

GNL = gnl.c gnl_utils.c 

OBJS = ${SRCS:.c=.o}

RM = rm -rf 

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	@${RM} $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all