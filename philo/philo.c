/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:37:21 by hhoummad          #+#    #+#             */
/*   Updated: 2021/09/17 11:37:25 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead(t_philo *ph, int i)
{
	pthread_mutex_lock(&ph->data->eat[i]);
	pthread_mutex_lock(ph->data->display);
	printf("%04ld %d died\n", get_time() - ph->data->start, i + 1);
	return (0);
}

void	*sup(void *arg)
{
	t_philo	*ph;
	int		i;
	int		k;

	ph = arg;
	i = 0;
	k = (int)get_time();
	while (1)
	{
		if (ph[i].is_eat == 0 && k - ph[i].t_eat >= ph[i].data->time_die)
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
			k = (int)get_time();
		}
	}
	return (0);
}

static void	free_destroy(t_philo *philo, t_data *data)
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
		return (error2("MALLOC failed", NULL));
	if (init_philo(philo, data) == 1)
		return (1);
	while (i < data->num_philo)
	{
		pthread_create(&(philo[i].ph), NULL, &rtn, &philo[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < data->num_philo)
	{
		pthread_create(&(philo[i].ph), NULL, &rtn, &philo[i]);
		i += 2;
	}
	pthread_create(&ph, NULL, &sup, philo);
	pthread_join(ph, NULL);
	free_destroy(philo, data);
	return (0);
}

int	main(int ac, char **av)
{
	int		err;
	t_data	*data;

	err = 0;
	if (ac < 5 || ac > 6)
		return (error("Wrong Numbre Of Arg", &err));
	data = malloc(sizeof(t_data));
	if (!data)
		return (error("MALLOC failed", &err));
	if (init_data(data, av + 1, ac, &err) == 1)
		return (1);
	if (start(data, 0) == 1)
		return (1);
	free(data->display);
	free(data->eat);
	free(data->fork);
	free(data);
	return (0);
}
