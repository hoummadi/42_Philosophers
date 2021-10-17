/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:22:20 by hhoummad          #+#    #+#             */
/*   Updated: 2021/10/17 21:22:13 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	t;
	long			usec;

	gettimeofday(&t, NULL);
	usec = ((t.tv_sec * 1000) + (t.tv_usec / 1000));
	return (usec);
}

void	ft_usleep(int time)
{
	int				t1;
	int				old;
	int				now;

	old = get_time();
	time = time / 1000;
	t1 = (time * 9) / 10;
	usleep(t1 * 1000);
	now = get_time();
	while (now - old < time)
		now = get_time();
}
