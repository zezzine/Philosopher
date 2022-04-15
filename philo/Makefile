# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 12:10:46 by zezzine           #+#    #+#              #
#    Updated: 2022/04/15 17:06:24 by zezzine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS =  -Wall -Wextra -Werror -c

SRCS =	main.c				\
		utils.c				\
		init_philo.c		\
		mutex_on.c			\
		time.c				\
		create_threads.c

OBJS =	main.o				\
		utils.o				\
		init_philo.o		\
		mutex_on.o			\
		time.o				\
		create_threads.o

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
