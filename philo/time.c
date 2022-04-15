/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:24:01 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/07 13:21:48 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(long start)
{
	struct timeval	t;
	long			millisecond;

	gettimeofday(&t, NULL);
	millisecond = ((t.tv_sec * 1000) + (t.tv_usec / 1000)) - start;
	return (millisecond);
}

void	ft_usleep(long time)
{
	long	old;

	old = get_time(0);
	time = time / 1000;
	while (get_time(old) < time)
		usleep(100);
}
