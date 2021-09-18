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
	if (*err == 0 && (data->num_philo > 200 || data->num_philo < 1
		|| data->time_die < 60 || data->time_eat < 60 || data->time_sleep < 60))
		return (error("Wrong Arg", err));
	if (*err == 1)
		return (1);
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
	ft_putendl_fd("done", 1);
	return (0);
}
