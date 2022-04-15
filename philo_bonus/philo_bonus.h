/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:00:47 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/12 17:47:44 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include<pthread.h>
# include<stdio.h>
# include<sys/time.h>
# include<semaphore.h>
# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>
# include <signal.h>

typedef struct s_data{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				num_eat;
	long			time_start;
	sem_t			*fork;
	sem_t			*display;
	sem_t			*eat;
}				t_data;

typedef struct s_philo{
	int			id;
	int			is_eat;
	long		time_eat;
	int			count_eat;
	t_data		*data;
	pid_t		pid;
	int			check;
}				t_philo;

int		checkatoi(char *str, int *err);
int		error(char *str, int *err);
int		error2(char *str, t_philo *p);
long	get_time(long time);
int		init_data(t_data *data, int ac, char **av, int *err);
void	ft_usleep(long time);
int		init_philo_x_semaphore(t_philo *philo);
void	routine(t_philo *ph);
void	*supervisor(void *arg, pid_t id, int i);
void	*check_death(void *arg);
int		checkatoi(char *str, int *err);
int		start_create_th(t_philo *philo);
void	*philo(void *arg);

#endif