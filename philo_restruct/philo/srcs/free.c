/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:17:23 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/26 21:28:17 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	free_philo(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
	{
		pthread_mutex_destroy(&(info->philo[i].last_eat_time_mutex));
		pthread_mutex_destroy(&(info->philo[i].eat_cnt_mutex));
	}
	free(info->philo);
	return (-1);
}

void	free_fork(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
		pthread_mutex_destroy(&(info->fork_mutex[i]));
	free(info->fork_mutex);
	free(info->fork);
}
