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
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_must_eat;
	int				num_eat;
	long			start;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*eat;
	pthread_mutex_t	*display;
}				t_data;

typedef struct s_philo
{
	int				is_eat;
	int				t_eat;
	int				c_eat;
	int				id;
	t_data			*data;
	pthread_t		ph;
}				t_philo;

void	ft_putendl_fd(char *s, int fd);
int		ft_strlen(char *s);
int		error(char *str, int *err);
int		error2(char *str, t_philo *p);
int		init_data(t_data *data, char **av, int ac, int *err);
int		checkatoi(char *str, int *err);
long	get_time(void);
void	ft_usleep(int time);
void	*rtn(void *arg);

#endif
