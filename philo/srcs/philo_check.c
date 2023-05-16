/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:20:20 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/16 16:18:17 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_eat_check(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(arg->eat));
	while (arg->must_eat_num != 0 && i < arg->philo_num \
	&& philo[i].eat_cnt >= arg->must_eat_num)
	{
		pthread_mutex_unlock(&(arg->eat));
		i++;
		pthread_mutex_lock(&(arg->eat));
	}
	pthread_mutex_unlock(&(arg->eat));
	pthread_mutex_lock(&(arg->eat));
	if (i == arg->philo_num)
		arg->eat_check = 1;
	pthread_mutex_unlock(&(arg->eat));
}

void	ft_death_check(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	current_time;

	while (!(arg->eat_check))
	{
		i = -1;
		usleep(200);
		while ((++i < arg->philo_num))
		{
			current_time = ft_time();
			pthread_mutex_lock(&(arg->eat));
			if ((current_time - philo[i].last_eat_time) >= arg->time_to_die)
			{
				pthread_mutex_unlock(&(arg->eat));
				ft_philo_printf(arg, i, DIE);
				pthread_mutex_lock(&(arg->die_mutex));
				arg->die = 1;
				pthread_mutex_unlock(&(arg->die_mutex));
				return ;
			}
			pthread_mutex_unlock(&(arg->eat));
		}
		ft_eat_check(arg, arg->philo);
	}
}
