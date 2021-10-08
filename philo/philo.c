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
		{
			pthread_mutex_lock(&ph->data->eat[i]);
			pthread_mutex_lock(ph->data->display);
			printf("%04ld %d dead |%d|\n", get_time() - ph->data->start, i + 1, (int)get_time() - ph[i].t_eat);
			return (0);
		}
		i = (i + 1) % ph[0].data->num_philo;
		if (i == 0)
		{
			if (ph[i].data->num_eat >= ph[i].data->num_philo)
			{
				pthread_mutex_lock(ph->data->display);
				printf("%04ld stop |%d| ****\n", get_time() - ph->data->start, ph->data->num_eat);
				return (0);
			}
			ft_usleep(500);
			k = (int)get_time();
		}
	}
	return (0);
}

static int	init_philo(t_philo *philo, t_data *data)
{
	int				i;

	i = -1;
	data->start = get_time();
	data->fork = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	data->eat = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	data->display = malloc(sizeof(pthread_mutex_t));
	if (!(data->fork) || !(data->eat) || !(data->display))
		return (error2("MALLOC failed", philo));
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
		philo[i].t_eat = data->start;
		philo[i].c_eat = 0;
	}
	return (0);
}

int	start(t_data *data)
{
	t_philo			*philo;
	pthread_t		ph;
	int				i;

	i = 0;
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
	free(philo);
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
	if (start(data) == 1)
		return (1);
	free(data->display);
	free(data->eat);
	free(data->fork);
	free(data);
	return (0);
}
