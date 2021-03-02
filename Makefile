# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 15:11:25 by lgomez-d          #+#    #+#              #
#    Updated: 2021/03/02 15:49:07 by lgomez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR		= ./libft

LIBFT	= ${DIR}/libft.a

NAME	= libftprintf.a

RM		= rm -f

FLAGS	= -c -Wall -Wextra -Werror

SRCS	= ft_printf.c ft_handle_flags.c ft_print_no_numbers.c ft_print_numbers.c \
ft_utils.c ft_handle_number.c ft_print_double.c ft_utils_double.c ft_utils2_double.c

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