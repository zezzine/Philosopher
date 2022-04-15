/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_on.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:36:30 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/12 18:23:58 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *ph, char *str, int id)
{
	pthread_mutex_lock(ph->data->display);
	printf("%04ld %d %s", get_time(ph->data->time_start),
		id + 1, str);
	pthread_mutex_unlock(ph->data->display);
}

void	take_forks(t_philo *ph)
{
	int	id;

	id = ph->id;
	pthread_mutex_lock(&ph->data->fork[id]);
	print_msg(ph, "has taken a fork\n", id);
	id = (id + 1) % ph->data->num_philo;
	pthread_mutex_lock(&ph->data->fork[id]);
	pthread_mutex_lock(&ph->data->eat[ph->id]);
	print_msg(ph, "has taken a fork\n", ph->id);
	ph->is_eat = 1;
}

void	eating(t_philo *ph)
{
	ph->time_eat = get_time(0);
	print_msg(ph, "is eating\n", ph->id);
	ft_usleep(ph->data->time_to_eat * 1000);
	ph->count_eat++;
	pthread_mutex_unlock(&ph->data->eat[ph->id]);
	if (ph->count_eat == ph->data->num_must_eat)
	{
		pthread_mutex_lock(ph->data->display);
		ph->data->num_eat++;
		pthread_mutex_unlock(ph->data->display);
	}
	ph->is_eat = 0;
}

void	sleeping(t_philo *ph)
{
	int	id;

	id = ph->id;
	pthread_mutex_unlock(&ph->data->fork[id]);
	id = (id + 1) % ph->data->num_philo;
	pthread_mutex_unlock(&ph->data->fork[id]);
	print_msg(ph, "is sleeping\n", ph->id);
	ft_usleep(ph->data->time_to_sleep * 1000);
	print_msg(ph, "thinking\n", ph->id);
}

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = arg;
	while (1)
	{
		take_forks(ph);
		eating(ph);
		sleeping(ph);
	}
	return (0);
}
