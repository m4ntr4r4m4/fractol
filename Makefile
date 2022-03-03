# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammoud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 17:43:34 by ahammoud          #+#    #+#              #
#    Updated: 2022/03/03 18:44:22 by ahammoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	./source/hook.c \
		   	./source/utils.c \
			./source/render.c \
			./source/mathfun.c \
			./source/mandelbort.c \
			./source/julia2.c \
			./source/multi-julia.c \
			./source/fractol.c

OBJS	=	${SRCS:.c=.o}

.c.o	:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes/

NAME	=	 fractol

CFLAGS	=	-Wall -Werror -Wextra 

MLXFLAGS =  -lmlx -framework OpenGL -framework AppKit


CC	=	gcc


${NAME}	:	${OBJS} 
			cd ./source/libft/ && make
			${CC} ${MLXFLAGS}  ${OBJS}  ./source/libft/libft.a -o ${NAME}

all	:	${NAME}

RM	=	rm -f

clean	:
		${MAKE} clean -C ./source/libft
		${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
