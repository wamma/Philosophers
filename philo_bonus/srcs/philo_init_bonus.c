/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:12:34 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/28 20:46:10 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_semaphore_init(t_info *info)
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

int	ft_philo_init(t_info *info)
{
	int	i;

	info->philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!(info->philo))
		return (-1);
	i = 0;
	while (i < info->philo_num)
	{
		info->philo[i].id = i;
		info->philo[i].last_eat_time = 0;
		info->philo[i].eat_count = 0;
		info->philo[i].info = info;
		i++;
	}
	return (0);
}

int	ft_info_init(t_info *info, int argc, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->die = 0;
	info->must_eat = 0;
	info->must_eat_flag = 0;
	info->eat_check = 0;
	info->start_time = ft_time();
	if (info->philo_num <= 0 || info->time_to_die <= 0 || \
	info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (-1);
	if (argc == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		if (info->must_eat <= 0)
			return (-1);
	}
	if (ft_semaphore_init(info))
		return (-1);
	if (ft_philo_init(info))
		return (-1);
}
