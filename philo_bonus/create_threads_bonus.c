/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:09:46 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/12 17:47:35 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (get_time(0) - philo->time_eat >= philo->data->time_to_die)
		{
			philo->check = 0;
			sem_wait(philo->data->display);
			printf("%04ld %d died\n", \
				get_time(philo->data->time_start), philo->id + 1);
			return ((void *)0);
		}
		usleep(100);
	}
}

int	start_create_th(t_philo *philo)
{
	int	i;

	if (init_philo_x_semaphore(philo) == 1)
		return (1);
	philo->data->time_start = get_time(0);
	philo->time_eat = philo->data->time_start;
	i = -1;
	while (++i < philo->data->num_philo)
	{
		philo->id = i;
		philo->pid = fork();
		if (philo->pid == 0)
			routine(philo);
		usleep(100);
	}
	return (0);
}
