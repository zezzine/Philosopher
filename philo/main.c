/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:00:52 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/12 18:24:24 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead(t_philo *ph, int i)
{
	pthread_mutex_lock(&(ph->data->eat[i]));
	pthread_mutex_lock(ph->data->display);
	printf("%04ld %d is dead\n", get_time(ph->data->time_start), i + 1);
	return (0);
}

void	*supervisor(void *arg)
{
	t_philo	*ph;
	int		i;
	int		k;

	ph = arg;
	k = (int)get_time(0);
	i = 0;
	while (1)
	{
		if (ph[i].is_eat == 0
			&& k - ph[i].time_eat >= ph[i].data->time_to_die)
			return (dead(ph, i));
		i = (i + 1) % ph[0].data->num_philo;
		if (i == 0)
		{
			if (ph[i].data->num_eat >= ph[i].data->num_philo)
			{
				pthread_mutex_lock(ph->data->display);
				return (0);
			}
			ft_usleep(500);
			k = (int)get_time(0);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		err;

	err = 0;
	if (ac < 5 || ac > 6)
		error("Bad args!!\n", &err);
	data = malloc(sizeof(t_data));
	if (!data)
		return (error("malloc failed\n", &err));
	if (init_data(data, ac, av + 1, &err) == 1)
		return (error("error", &err));
	if (start(data, 0) == 1)
		return (error("error\n", &err));
	return (0);
}
