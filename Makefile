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
			init.c						\
			format/init.c				\
			format/handle.c				\
			format/int.c				\
			format/char.c				\
			format/string.c				\
			format/default.c			\
			parameters/set_parameters.c	\
			output/bufferize.c


INC		=	-I ./includes -I ./srcs/format -I ./srcs/parameters -I ./srcs/output
LIBS	=	
CCFLAGS	=	-Wall -Wextra -g

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	main.c $(SRCS:.c=.o)

#--------------Actions----------------------#

.PHONY: LIBRARIES $(NAME) clean fclean re

all: $(NAME)

LIBRARIES:

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
