/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:20:20 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/20 20:21:26 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death_check(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	current_time;

	while (!(arg->die))
	{
		if (arg->must_eat_num != 0 && (arg->philo_num == arg->finish_eat))
		{
			arg->die = 1;
			break ;
		}
		i = 0;
		while (i < arg->philo_num)
		{
			current_time = ft_time();
			if (current_time - philo[i].last_eat_time <= arg->time_to_die)
			{
				ft_philo_printf(arg, i, "died");
				arg->die = 1;
				break ;
			}
			i++;
		}
	}
	return (0);
}
