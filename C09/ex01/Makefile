NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJS = ${SRCS:.c=.o}
CC = gcc -Wall -Werror -Wextra

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

.c.o:
	${CC} -I includes -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re