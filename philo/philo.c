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
