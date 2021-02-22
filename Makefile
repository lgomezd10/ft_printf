# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 15:11:25 by lgomez-d          #+#    #+#              #
#    Updated: 2021/02/22 15:48:59 by lgomez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR		= ./libft

LIBFT	= ${DIR}/libft.a

NAME	= libftprintf.a

RM		= rm -f

FLAGS	= -c -Wall -Wextra -Werror

SRCS	= ft_printf.c handle_flags.c print_no_numbers.c print_numbers.c utils.c \
handle_number.c print_bonus.c 

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