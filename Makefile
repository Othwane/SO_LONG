NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRCS =  so_long.c\
		checker.c\
		errorhandler.c\
		wineed.c\
		init.c

GNL = gnl.c gnl_utils.c 

OBJS = ${SRCS:.c=.o}

RM = rm -rf 

all: ${NAME}

%.o : %.c
	${CC} $^ -c -o $@

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	@rm -rf $(OBJ)

fclean:		clean
	@rm -rf $(NAME)

re:	fclean all