/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:21:10 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/07 17:24:30 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}

int	error(char *str, int *err)
{
	ft_putendl_fd(str, 2);
	*err = 1;
	return (1);
}

int	error2(char *str, t_philo *p)
{
	ft_putendl_fd(str, 2);
	free(p);
	return (1);
}
