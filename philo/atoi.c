/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:32:11 by hhoummad          #+#    #+#             */
/*   Updated: 2021/09/17 13:32:14 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atoi(const char *str)
{
	long	r;
	int		i;

	r = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r <= ((9223372036854775807 - (str[i] - 48)) / 10))
			r = r * 10 + (str[i] - 48);
		else
		{
			r = 9223372036854775807;
			break ;
		}
		i++;
	}
	return (r);
}

int	checkatoi(char *str, int *err)
{
	long	i;
	long	j;

	i = 0;
	if (*err == 1)
		return (1);
	if (!str)
		return (error("Args Must Be Integer", err));
	j = i;
	while (str[j] == '0')
		j++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (error("Args Must Be Integer", err));
		i++;
	}
	if (i - j > 11)
		return (error("Args Must Be Integer", err));
	i = ft_atoi(str);
	if (i > 2147483647 || i < 0)
		return (error("Args Must Be Integer", err));
	return (i);
}
