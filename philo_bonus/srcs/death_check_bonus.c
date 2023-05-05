/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:15:35 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/05 19:48:32 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_death_check(t_philo *philo)
{
	long long	current_time;
	long long	gap_time;

	current_time = ft_time();
	sem_wait(philo->sem_last_eat_time);
	gap_time = current_time - philo->last_eat_time;
	sem_post(philo->sem_last_eat_time);
	if (gap_time > philo->info->time_to_die)
		return (1);
	return (0);
}
