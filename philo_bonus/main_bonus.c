/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:11:26 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/12 17:28:45 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(t_philo *ph)
{
	pthread_t	id1;
	pthread_t	id2;

	pthread_create(&id1, NULL, &philo, ph);
	pthread_create(&id2, NULL, &check_death, ph);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	exit(ph->check);
}

void	free_all_philos(t_philo *philo)
{
	sem_close(philo->data->fork);
	sem_close(philo->data->eat);
	sem_close(philo->data->display);
	sem_unlink("/semaphore");
	sem_unlink("/eat");
	sem_unlink("/print");
	free(philo->data);
	free(philo);
}

void	kill_all_proccessors(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->num_philo - 1)
		kill(philo[i].pid, SIGKILL);
	free_all_philos(philo);
}

int	_help(int i, t_philo *philo, int status)
{
	while (i < philo->data->num_philo)
	{
		waitpid(-1, &status, 0);
		if (status == 0)
		{
			kill_all_proccessors(philo);
			return (0);
		}
		i++;
	}
	free_all_philos(philo);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	int		status;
	int		err;
	int		i;

	i = 0;
	err = 0;
	status = 0;
	if (ac < 5 || ac > 6)
		error("Bad args!!\n", &err);
	philo = malloc(sizeof(t_philo));
	philo->data = malloc(sizeof(t_data));
	if (!philo || !philo->data)
		return (error2("Allocation failed!!\n", philo));
	if (init_data(philo->data, ac, av + 1, &err) == 1)
		return (error("error", &err));
	if (start_create_th(philo) == 1)
		return (error("error\n", &err));
	return (_help(i, philo, status));
}
