/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:22:20 by hhoummad          #+#    #+#             */
/*   Updated: 2021/09/22 16:22:22 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	t;
	long 			usec;

	gettimeofday(&t, NULL);
	usec = ((t.tv_sec * 1000) + (t.tv_usec / 1000));
	return (usec);
}

void	ft_usleep(int time)
{
	int				t1;
	int				old;
	int				now;
	struct timeval	t;

	gettimeofday(&t, NULL);
	old = t.tv_sec * 1000000 + t.tv_usec;
	t1 = (time * 9) / 10;
	usleep(t1);
	gettimeofday(&t, NULL);
	now = t.tv_sec * 1000000 + t.tv_usec;
	while (now - old < time)
	{
		usleep((time - (now - old)) / 2);
		gettimeofday(&t, NULL);
		now = t.tv_sec * 1000000 + t.tv_usec;
	}
}
