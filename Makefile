NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
LIBFT = ./libft/libft.a


SRCS =  ./srcs/so_long.c\
		./srcs/checker.c\
		./srcs/errorhandler.c\
		./srcs/init.c \
		./srcs/readmap.c \
		./srcs/mapchecker.c \
		./srcs/check_valid_path.c \
		./srcs/directions.c \
		./srcs/rungame.c 

OBJS = ${SRCS:.c=.o}

RM = rm -rf 

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	@make all -C ./libft
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -lmlx -framework OpenGL -framework AppKit $ -o ${NAME}

clean:
	@make clean -C ./libft
	@${RM} $(OBJS)

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

re:	fclean all