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

void	*r(void	*arg)
{
	t_philo	*ph;
	
	ph = arg;
	printf("HI, I'm %d\n", ph->id);
	usleep(100);
	return (0);
}

void	*sup(void	*arg)
{
	t_philo	*ph;
	int		i;
	int		k;
	
	ph = arg;
	printf("HI, I'm sup %d\n", ph[0].id);
	i = 0;
	k = 0;
	printf("%ld\n", get_time() - ph[0].data->start);
	while (1)
	{
		if (ph[i].is_eat == 0)
			;
		i = (i + 1) % ph[0].data->num_philo;
		k++;
		if (k == ph[0].data->num_philo * 1000)
			break ;
	}
	printf("%ld\n", get_time() - ph[0].data->start);
	return (0);
}

void	init_philo(t_philo *philo, t_data *data)
{
	int				i;

	i = -1;
	data->start = get_time();
	while (++i < data->num_philo)
	{
		philo[i].id = i;
		philo[i].data = data;
		philo[i].is_eat = 0;
		philo[i].t_eat = data->start;
		philo[i].c_eat = 0;
	}
}

int	start(t_data *data)
{
	t_philo			*philo;
	int				i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->num_philo + 1);	//protect
	init_philo(philo, data);

	printf("%d\n", 0);

	while (i < data->num_philo)
	{
		pthread_create(&(philo[i].ph), NULL, &r, &philo[i]);
		i += 2;
	}
	i = 1;
	while (i < data->num_philo)
	{
		pthread_create(&(philo[i].ph), NULL, &r, &philo[i]);
		i += 2;
	}
	pthread_create(&(philo[data->num_philo].ph), NULL, &sup, philo);
	pthread_join(philo[data->num_philo].ph, NULL);

	// printf("%ld\n", get_time() - data->start);
	ft_usleep(100*1000);
	// printf("%ld\n", get_time() - data->start);
	free(philo);
	return (0);
}

int	main(int ac, char **av)
{
	int		err;
	t_data	data;

	err = 0;
	if (ac < 5 || ac > 6)
		return (error("Wrong Numbre Of Arg", &err));
	if (init_data(&data, av + 1, ac, &err) == 1)
		return (1);
	start(&data);
	ft_putendl_fd("done", 1);
	return (0);
}
