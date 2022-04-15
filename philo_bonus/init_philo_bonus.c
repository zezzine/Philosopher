/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:04:50 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/12 17:46:40 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_data(t_data *data, int ac, char **av, int *err)
{
	data->num_philo = checkatoi(av[0], err);
	data->time_to_die = checkatoi(av[1], err);
	data->time_to_eat = checkatoi(av[2], err);
	data->time_to_sleep = checkatoi(av[3], err);
	if (ac == 6)
		data->num_must_eat = checkatoi(av[4], err);
	else
		data->num_must_eat = -1;
	data->num_eat = 0;
	if (*err == 0 && (data->num_philo > 200 || data->num_philo < 1
			|| data->time_to_die < 60 || data->time_to_eat < 60
			|| data->time_to_sleep < 60))
		return (error("bad argument!!\n", err));
	if (*err == 1 || data->num_must_eat == 0)
		return (1);
	return (0);
}

int	init_philo_x_semaphore(t_philo *philo)
{
	sem_unlink("/fork");
	sem_unlink("/eat");
	sem_unlink("/print");
	philo->data->fork = sem_open("/fork", O_CREAT
			| O_EXCL, 0644, philo->data->num_philo);
	philo->data->eat = sem_open("/eat", O_CREAT
			| O_EXCL, 0644, philo->data->num_philo);
	philo->data->display = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	if (philo->data->fork == SEM_FAILED || philo->data->display == SEM_FAILED)
		return (1);
	philo->is_eat = 0;
	philo->count_eat = 0;
	philo->check = 1;
	return (0);
}
