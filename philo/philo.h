/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:54:59 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/12 17:37:33 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h> 

typedef struct s_data{
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_must_eat;
	int					num_eat;
	long				time_start;
	pthread_mutex_t		*display;
	pthread_mutex_t		*fork;
	pthread_mutex_t		*eat;
}	t_data;

typedef struct s_philo{
	int				id;
	int				is_eat;
	int				time_eat;
	int				count_eat;
	t_data			*data;
	pthread_t		ph;
}	t_philo;

int		checkatoi(char *str, int *err);
int		error(char *str, int *err);
int		error2(char *str, t_philo *p);
long	get_time(long time);
void	*routine(void *arg);
int		init_philo_x_mutex(t_data *data, t_philo *philo);
int		start(t_data *data, int i);
int		init_data(t_data *data, int ac, char **av, int *err);
void	ft_usleep(long time);
void	*supervisor(void *arg);

#endif