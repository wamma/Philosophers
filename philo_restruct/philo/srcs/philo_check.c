/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:20:20 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/27 10:49:54 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_eat_check(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (info->must_eat != 0 && i < info->philo_num \
	&& philo[i].eat_cnt > info->must_eat)
		i++;
	if (i == info->philo_num)
		info->eat_check = 1;
}

void	ft_death_check(t_info *info, t_philo *philo)
{
	int			i;
	long long	current_time;

	while (!(info->eat_check))
	{
		i = -1;
		while ((++i < info->philo_num) && (!(info->die)))
		{
			current_time = ft_time();
			pthread_mutex_lock(&(info->eat));
			if ((current_time - philo[i].last_eat_time) > info->time_to_die)
			{
				ft_philo_printf(info, i, DIE);
				info->die = 1;
			}
			pthread_mutex_unlock(&(info->eat));
		}
		if (info->die)
			break ;
		ft_eat_check(info, info->philo);
	}
}
