/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heongjunpark <heongjunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:34:24 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/30 22:02:05 by heongjunpar      ###   ########.fr       */
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
	info->die = DIE;
	i = 0;
	while (i < info->philo_num)
	{
		sem_post(info->sem_full);
		i++;
	}
	pthread_join(info->philo->thread_id, NULL);
	free_info();
	return (0);
}
