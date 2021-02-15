DIR		= ./libft

LIBFT	= ${DIR}/libft.a

NAME	= libftprintf.a

RM		= rm -f

FLAGS	= -c -Wall -Wextra -Werror

SRCS	= ft_printf.c print_no_numbers.c print_numbers.c utils.c

OBJ		= ${SRCS:.c=.o}

all:	${NAME}

${LIBFT}:
			${MAKE} -C ${DIR}

${NAME}:	${OBJ} ${LIBFT}
			ar rc ${NAME} ${OBJ} ${LIBFT}

clean:
		${MAKE} clean -C ${DIR}
		${RM} ${OBJ}

fclean:		clean
			${MAKE} fclean -C ${DIR}
			${RM} ${OBJ}

re:		fclean all