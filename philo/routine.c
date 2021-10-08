/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:04:36 by hhoummad          #+#    #+#             */
/*   Updated: 2021/09/23 12:04:42 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <errno.h>
#include <string.h>

void	take_forks(t_philo *ph)
{
	int	id;

	id = ph->id;
	pthread_mutex_lock(&ph->data->fork[id]);
	pthread_mutex_lock(ph->data->display);
	printf("%04ld %d has taken a fork\n", get_time() - ph->data->start,
		id + 1);
	pthread_mutex_unlock(ph->data->display);
	id = (id + 1) % ph->data->num_philo;
	pthread_mutex_lock(&ph->data->fork[id]);
	pthread_mutex_lock(&ph->data->eat[ph->id]);
	ph->is_eat = 1;
	pthread_mutex_lock(ph->data->display);
	printf("%04ld %d has taken a fork\n", get_time() - ph->data->start,
		ph->id + 1);
	pthread_mutex_unlock(ph->data->display);
}

void	eating(t_philo *ph)
{
	ph->t_eat = get_time();
	pthread_mutex_lock(ph->data->display);
	printf("%04ld %d is eating\n", get_time() - ph->data->start, ph->id + 1);
	pthread_mutex_unlock(ph->data->display);
	ft_usleep(ph->data->time_eat * 1000);
	ph->c_eat++;
	pthread_mutex_unlock(&ph->data->eat[ph->id]);
	if (ph->c_eat == ph->data->num_must_eat)
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
	pthread_mutex_lock(ph->data->display);
	printf("%04ld %d is sleeping\n", get_time() - ph->data->start, ph->id + 1);
	pthread_mutex_unlock(ph->data->display);
	ft_usleep(ph->data->time_sleep * 1000);
	pthread_mutex_lock(ph->data->display);
	printf("%04ld %d is thinking\n", get_time() - ph->data->start, ph->id + 1);
	pthread_mutex_unlock(ph->data->display);
}

void	*rtn(void *arg)
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
