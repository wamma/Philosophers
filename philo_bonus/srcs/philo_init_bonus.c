/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:12:34 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/05 21:15:16 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_semaphore_init(t_info *info)
{
	sem_unlink("sem_start");
	info->sem_start = sem_open("sem_start", O_CREAT, 0644, 1);
	sem_unlink("sem_finish");
	info->sem_finish = sem_open("sem_finish", O_CREAT, 0644, 0);
	sem_unlink("print");
	info->print = sem_open("print", O_CREAT, 0644, 1);
	sem_unlink("fork");
	info->fork = sem_open("fork", O_CREAT, 0644, info->philo_num);
	sem_unlink("sem_full");
	info->sem_full = sem_open("sem_full", O_CREAT, 0644, 0);
}

int	ft_philo_init(t_info *info, t_philo *philo, int i)
{
	philo->id = i;
	philo->last_eat_time = 0;
	philo->eat_count = 0;
	philo->info = info;
	sem_unlink("sem_last_eat_time");
	philo->sem_last_eat_time = sem_open("sem_last_eat_time", \
	O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("sem_eat_count");
	philo->sem_eat_count = sem_open("sem_eat_count", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("sem_eat_count");
	return (0);
}

int	ft_info_init(t_info *info, int argc, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->must_eat = 0;
	info->must_eat_flag = 0;
	info->eat_check = 0;
	info->die = 0;
	if (info->philo_num <= 0 || info->time_to_die <= 0 || \
	info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (-1);
	if (argc == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		if (info->must_eat <= 0)
			return (-1);
	}
	info->philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!(info->philo))
		return (-1);
	ft_semaphore_init(info);
	return (0);
}
