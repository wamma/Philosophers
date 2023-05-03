/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:08:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/03 22:30:23 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*ft_philo_monitor(void *arg)
{
	t_philo	*philo;
	int		dup_flag;

	philo = arg;
	dup_flag = 0;
	while (1)
	{
		if (ft_death_check(philo))
		{
			ft_philo_printf(arg, philo->id, DIE);
			philo->info->die = 1;
			sem_post(philo->info->sem_finish);
		}
		if (!dup_flag && philo->info->must_eat_flag)
		{
			sem_wait(philo->eat_count);
			if (philo->eat_count >= philo->info->must_eat)
			{
				sem_post(philo->info->sem_full);
				dup_flag = 1;
			}
			sem_post(philo->eat_count);
		}
	}
}

int	routine(t_info *info, int i)
{
	sem_wait(info->sem_start);
	sem_post(info->sem_start);
	if (pthread_create(&(info->philo->thread_id), NULL, \
	ft_philo_monitor, &(info->philo[i])))
		return (-1);
}
