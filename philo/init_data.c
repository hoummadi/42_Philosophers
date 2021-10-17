/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:31:17 by hhoummad          #+#    #+#             */
/*   Updated: 2021/09/21 15:31:19 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **av, int ac, int *err)
{
	data->num_philo = checkatoi(av[0], err);
	data->time_die = checkatoi(av[1], err);
	data->time_eat = checkatoi(av[2], err);
	data->time_sleep = checkatoi(av[3], err);
	if (ac == 6)
		data->num_must_eat = checkatoi(av[4], err);
	else
		data->num_must_eat = -1;
	data->num_eat = 0;
	if (*err == 0 && (data->num_philo > 200 || data->num_philo < 1
			|| data->time_die < 60 || data->time_eat < 60
			|| data->time_sleep < 60))
		return (error("Bad Arg", err));
	if (*err == 1 || data->num_must_eat == 0)
		return (1);
	return (0);
}

int	init_philo(t_philo *philo, t_data *data)
{
	int	i;

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
