/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:51:55 by zezzine           #+#    #+#             */
/*   Updated: 2022/04/11 21:52:02 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atoi(const char *str)
{
	long	r;
	int		i;

	r = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r <= ((9223372036854775807 - (str[i] - 48)) / 10))
			r = r * 10 + (str[i] - 48);
		else
		{
			r = 9223372036854775807;
			break ;
		}
		i++;
	}
	return (r);
}

int	checkatoi(char *str, int *err)
{
	long	i;
	long	j;

	i = 0;
	if (*err == 1)
		return (1);
	if (!str)
		return (error("Args Must be integer", err));
	j = i;
	while (str[j] == '0')
		j++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (error("Args Must be integer", err));
		i++;
	}
	if (i - j > 11)
		return (error("Args Must be integer", err));
	i = ft_atoi(str);
	if (i > 2147483647 || i < 0)
		return (error("Args Must Be Integer", err));
	return (i);
}

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
