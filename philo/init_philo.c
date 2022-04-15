/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:04:50 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/08 11:32:28 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	init_philo_x_mutex(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	data->time_start = get_time(0);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	data->eat = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	data->display = malloc(sizeof(pthread_mutex_t));
	if (!(data->fork) || !(data->eat) || !(data->display))
		return (error2("reservation failed!", philo));
	while (++i < data->num_philo)
	{
		pthread_mutex_init(&(data->fork[i]), NULL);
		pthread_mutex_init(&(data->eat[i]), NULL);
	}
	pthread_mutex_init(data->display, NULL);
	i = -1;
	while (++i < data->num_philo)
	{
		philo[i].id = i;
		philo[i].data = data;
		philo[i].is_eat = 0;
		philo[i].time_eat = data->time_start;
		philo[i].count_eat = 0;
	}
	return (0);
}
