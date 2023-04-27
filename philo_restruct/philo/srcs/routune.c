/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routune.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:03:50 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/27 12:31:29 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_take_fork(t_philo *philo)
{
	phtread_mutex_lock(&(philo->info->fork_mutex[philo->left_fork]));
	philo->info->fork[philo->left_fork] = 1;
	if (ft_philo_printf(philo->info, philo->id, TAKE_FORK) < 0)
	{
		philo->info->fork[philo->left_fork] = 0;
		pthread_mutex_unlock(&(philo->info->fork_mutex));
		return ;
	}
	pthread_mutex_lock(&(philo->info->fork_mutex[philo->right_fork]));
	philo->info->fork[philo->right_fork] = 1;
	if (ft_philo_printf(philo->info, philo->id, ))
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&(philo->info->mutex_start));
	pthread_mutex_unlock(&(philo->info->mutex_start));
	if (philo->id & 2 == 1)
		usleep(1000);
	while (1)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_take_off_fork(philo);
		ft_sleep(philo);
		ft_think(philo);
		phtread_mutex_lock(&(philo->info->mutex_finish));
		if (philo->info->finish_flag != 0)
		{
			pthread_mutex_destroy(&(philo->info->mutex_finish));
			break ;
		}
		pthread_mutex_unlock(&(philo->info->mutex_finish));
		usleep(100);
	}
	return (0);
}
