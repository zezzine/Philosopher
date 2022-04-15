/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:36:30 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/12 17:28:35 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_msg(t_philo *philo, char *str)
{
	if (philo->check == 1)
	{
		sem_wait(philo->data->display);
		printf("%04ld %d %s\n", get_time(philo->data->time_start),
			philo->id + 1, str);
		sem_post(philo->data->display);
	}
}

void	take_forks(t_philo *ph)
{
	sem_wait(ph->data->fork);
	print_msg(ph, "has taken a fork");
	sem_wait(ph->data->fork);
	sem_wait(ph->data->eat);
	ph->is_eat = 1;
	print_msg(ph, "has taken a fork");
}

void	eating(t_philo *ph)
{
	ph->time_eat = get_time(0);
	print_msg(ph, "is eating");
	ft_usleep(ph->data->time_to_eat * 1000);
	ph->count_eat++;
	sem_post(ph->data->eat);
	if (ph->count_eat == ph->data->num_must_eat)
	{
		sem_post(ph->data->fork);
		sem_post(ph->data->fork);
		exit(1);
	}
	ph->is_eat = 0;
}

void	sleeping(t_philo *ph)
{
	sem_post(ph->data->fork);
	sem_post(ph->data->fork);
	print_msg(ph, "is sleeping");
	ft_usleep(ph->data->time_to_sleep * 1000);
	print_msg(ph, "is thinking");
}

void	*philo(void *arg)
{
	t_philo		*ph;

	ph = arg;
	while (ph->check == 1)
	{
		take_forks(ph);
		eating(ph);
		sleeping(ph);
	}
	return (0);
}
