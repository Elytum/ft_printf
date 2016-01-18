# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by achazal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC		=	gcc
#--------------Name-------------------------#
NAME	=	ft_printf
MYPATH	=	$(HOME)
#--------------Sources----------------------#
FILES	=	ft_printf.c					\
			format/init.c				\
			format/interprete.c			\
			format/int.c				\
			format/char.c				\
			format/string.c				\
			format/percent.c			\
			format/default.c			\
			format/n.c					\
			parameters/init.c			\
			parameters/set_parameters.c	\
			parameters/blank.c			\
			parameters/justify.c		\
			parameters/pad.c			\
			parameters/sign.c			\
			parameters/specification.c	\
			parameters/width.c			\
			parameters/precision.c		\
			converters/ft_itoa.c		\
			output/bufferize.c			\
			debug/print_parameters.c


INC		=	-I ./includes -I ./srcs/format -I ./srcs/parameters -I ./srcs/output -I ./srcs/converters -I ./srcs/debug
CCFLAGS	=	-Wall -Wextra -g -O3

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	main.o $(SRCS:.c=.o)

#--------------Actions----------------------#

.PHONY: LIBRARIES $(NAME) clean fclean re

all: $(NAME)

LIBRARIES:
	make -C lib

$(NAME): LIBRARIES $(OBJS)
	$(CC) $(CCFLAGS) $(INC) $(OBJS) -o $(NAME) $(LIBS) -O3

%.o: %.c
	$(CC) $(CCFLAGS) -c  $(INC) $< -o $@
	
clean:
	rm -f $(OBJS)
	
fclean:	clean
	rm -f $(NAME)

re: fclean all
	make
