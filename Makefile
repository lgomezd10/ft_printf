DIR		= ./libft

LIBFT	= ${DIR}/libft.a

NAME	= libftprintf.a

RM		= rm -f

FLAGS	= -c -Wall -Wextra -Werror

SRCS	= ft_printf.c print_no_numbers.c print_numbers.c utils.c

OBJS		= ${SRCS:.c=.o}

all:	${NAME}

${LIBFT}:
			${MAKE} -C ${DIR}

${NAME}:	${OBJS} ${LIBFT}
			cp ${LIBFT} ${NAME}
			ar rc ${NAME} ${OBJS}

bonus:	${NAME}

clean:
		${MAKE} clean -C ${DIR}
		${RM} ${OBJS}

fclean:		clean
			${MAKE} fclean -C ${DIR}
			${RM} ${NAME}

re:		fclean all

.PHONY:	all bonus clean fclean re