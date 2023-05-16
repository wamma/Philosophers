/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:45:09 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/16 15:45:25 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->info->forks);
	ft_printf(FORK, philo);
	sem_wait(philo->info->forks);
	ft_printf(FORK, philo);
}

void	ft_eat(t_philo *philo)
{
	ft_printf(EAT, philo);
	if (philo->info->eat_count != -1)
		philo->info->current_eat++;
	usleep(philo->info->time_to_eat * 1000);
	philo->eating_time = ft_time();
	philo->next_meal = philo->eating_time + (long long)philo->info->time_to_die;
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}

void	ft_sleep(t_philo *philo)
{
	ft_printf(SLEEP, philo);
	usleep(philo->info->time_to_sleep * 1000);
}
