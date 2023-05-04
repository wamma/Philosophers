/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:34:24 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/04 20:45:36 by hyungjup         ###   ########.fr       */
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
			ft_philo_printf(arg, philo->id, "died");
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
	return (0);
}

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
	if (info->die != 1)
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
	int			i;
	pthread_t	sub_info;

	if (pthread_create(sub_info, NULL, ft_pthread, info))
		return (-1);
	sem_wait(info->sem_finish);
	kill_process(info);
	info->die = 1;
	i = 0;
	while (i < info->philo_num)
	{
		sem_post(info->sem_full);
		i++;
	}
	pthread_join(sub_info NULL);
	free_info();
	return (0);
}
