# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/18 13:05:02 by hhoummad          #+#    #+#              #
#    Updated: 2021/09/18 13:05:04 by hhoummad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philo.h

FLAGS =  -Wall -Wextra -Werror -c

SRCS =	philo.c		\
		errors.c	\
		atoi.c		\
		tools.c

OBJS =	philo.o		\
		errors.o	\
		atoi.o		\
		tools.o

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
		@gcc $(FLAGS) $(SRCS)
		@gcc $(OBJS) -o $(NAME)
		@echo "make philo"

clean:
	@rm -f *.o

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
