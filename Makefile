# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboia-pe <rboia-pe@student.42porto.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 01:54:21 by rboia-pe          #+#    #+#              #
#    Updated: 2023/04/08 01:54:21 by rboia-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME	:= get_next_line.a
		
SRCS =$(wildcard *.c)

SRCS_O	:= ${SRCS:.c=.o}
OBJS	:= ${SRCS_O}

CC		:= cc
RM		:= /bin/rm -f
CFLAGS	:= -Wall -Wextra -Werror -I*.h

CL := ar -rc
RL := ar -s

all: ${NAME}

${NAME}: ${SRCS_O}
	${CL} ${NAME} ${SRCS_O}
	${RL} ${NAME}

clean:
	${RM} ${OBJS} ./a.out

fclean: clean
	${RM} ${NAME}

re: fclean all

author: 
	@printf "rboia-pe\n"

norm:
	norminette -R CheckForbiddenSourceHeader *.c
	norminette -R CheckDefine *.h

.PHONY: clean fclean norm all bonus re author
