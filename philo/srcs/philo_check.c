/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:20:20 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/25 21:47:41 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_eat_check(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	while (arg->must_eat_num != 0 && i < arg->philo_num && philo[i].eat_cnt > arg->must_eat_num)
		i++;
	if (i == arg->philo_num)
		arg->eat_check = 1;
}

int	ft_death_check(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	current_time;

	while (!(arg->eat_check))
	{
		i = -1;
		while ((++i < arg->philo_num) && (!(arg->die)))
		{
			pthread_mutex_lock(&(arg->eat));
			current_time = ft_time();
			if ((current_time - philo[i].last_eat_time) > arg->time_to_die)
			{
				ft_philo_printf(arg, i, DIE);
				arg->die = 1;
			}
			pthread_mutex_unlock(&(arg->eat));
		}
		if (arg->die)
			break ;
		ft_eat_check(arg, arg->philo);
	}
	return (0);
}
