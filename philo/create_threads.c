/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:09:46 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/11 21:54:29 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_x_destroy(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_destroy(&(data->fork[i]));
		pthread_mutex_destroy(&(data->eat[i]));
	}
	pthread_mutex_destroy(data->display);
	free(philo);
}

int	start(t_data *data, int i)
{
	t_philo		*philo;
	pthread_t	ph;

	philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!philo)
		return (error2("Allocation failed!!\n", philo));
	if (init_philo_x_mutex(data, philo) == 1)
		return (1);
	while (i < data->num_philo)
	{
		pthread_create(&(philo[i].ph), NULL, &routine, &philo[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < data->num_philo)
	{
		pthread_create(&(philo[i].ph), NULL, &routine, &philo[i]);
		i += 2;
	}
	pthread_create(&ph, NULL, &supervisor, philo);
	pthread_join(ph, NULL);
	free_x_destroy(data, philo);
	return (0);
}
