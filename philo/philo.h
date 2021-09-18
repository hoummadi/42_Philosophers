/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:37:31 by hhoummad          #+#    #+#             */
/*   Updated: 2021/09/17 11:37:33 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int		num_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_must_eat;
}			t_data;

void	ft_putendl_fd(char *s, int fd);
int		error(char *str, int *err);
int		checkatoi(char *str, int *err);

#endif
