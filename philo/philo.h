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

typedef struct s_philo
{
	bool	is_eat;
	int		t_eat;
	int		c_eat;
	int		id;
	void	*data;
}			t_philo;

void	ft_putendl_fd(char *s, int fd);
int		ft_strlen(char *s);
int		error(char *str, int *err);
int		init_data(t_data *data, char **av, int ac, int *err);
int		checkatoi(char *str, int *err);

#endif
