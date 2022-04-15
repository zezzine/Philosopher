# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 12:10:46 by zezzine           #+#    #+#              #
#    Updated: 2022/04/15 17:04:59 by zezzine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BONUS = philo_bonus

FLAGS =  -Wall -Wextra -Werror -c

SRCSB = main_bonus.c				\
		utils_bonus.c				\
		init_philo_bonus.c		\
		semaphore_bonus.c			\
		time_bonus.c				\
		create_threads_bonus.c

OBJB =	main_bonus.o				\
		utils_bonus.o				\
		init_philo_bonus.o			\
		semaphore_bonus.o			\
		time_bonus.o				\
		create_threads_bonus.o

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRCSB)
		@gcc $(FLAGS) $(SRCSB)
		@gcc $(OBJB) -o $(NAME_BONUS)
		@echo "make philo bonus"

clean:
	@rm -f *.o

fclean:	clean
	@rm -f $(NAME_BONUS)

re:	fclean all

.PHONY: all clean fclean re bonus
