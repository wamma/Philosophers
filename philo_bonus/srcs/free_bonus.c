/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:08:23 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/02 14:49:31 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	kill_process(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		if (info->philo[i].pid > 0)
			kill(info->philo[i].pid, SIGTERM);
		else
			break ;
		i++;
	}
	free(info->philo);
}

void	free_info(void)
{
	sem_unlink("sem_start");
	sem_unlink("sem_finish");
	sem_unlink("print");
	sem_unlink("fork");
	sem_unlink("sem_full");
}