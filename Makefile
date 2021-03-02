# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 15:11:25 by lgomez-d          #+#    #+#              #
#    Updated: 2021/02/26 08:34:39 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR		= ./libft

LIBFT	= ${DIR}/libft.a

NAME	= libftprintf.a

RM		= rm -f

FLAGS	= -c -Wall -Wextra -Werror

SRCS	= ft_printf.c handle_flags.c print_no_numbers.c print_numbers.c utils.c \
handle_number.c ft_print_double.c ft_utils_double.c ft_utils2_double.c

OBJS		= ${SRCS:.c=.o}

all:	${NAME}

${LIBFT}:
			${MAKE} bonus -C ${DIR}

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