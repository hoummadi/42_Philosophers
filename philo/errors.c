/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:19:42 by hhoummad          #+#    #+#             */
/*   Updated: 2021/10/17 21:22:05 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *str, int *err)
{
	ft_putendl_fd(str, 2);
	*err = 1;
	return (1);
}

int	error2(char *str, t_philo *p)
{
	ft_putendl_fd(str, 2);
	free(p);
	return (1);
}
