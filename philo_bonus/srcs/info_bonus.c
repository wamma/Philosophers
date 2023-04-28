/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:34:24 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/28 21:08:08 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*ft_pthread(void *arg)
{
	t_info		*info;
	int			i;
	long long	time_stamp;
	long long	current_time;

	info = arg;
	i = 0;
	while (i < info->philo_num)
	{
		sem_wait(info->sem_finish);
		i++;
	}
	if (info->die != DIE)
	{
		sem_wait(info->print);
		current_time = ft_time();
		time_stamp = current_time - info->start_time;
		printf("%ld all philosophers are full\n", time_stamp);
		sem_post(info->sem_finish);
	}
	return (0);
}

int	info_start(t_info *info, t_philo *philo)
{
	int	i;

	if (pthread_create(&(info->philo->thread_id), NULL, ft_pthread, info))
		return (-1);
	sem_wait(info->sem_finish);
	kill_process(info);
}
