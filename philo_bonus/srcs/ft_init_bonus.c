/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:20:00 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/18 15:52:48 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_semaphore_init(t_info *info)
{
	sem_unlink("death");
	info->death = sem_open("death", O_CREAT, 0600, 1);
	sem_unlink("print");
	info->print = sem_open("print", O_CREAT, 0600, 1);
	sem_unlink("stop");
	info->stop = sem_open("stop", O_CREAT, 0600, 1);
	sem_unlink("forks");
	info->forks = sem_open("forks", O_CREAT, 0600, info->philo_num);
}

int	ft_philo_init(t_info *info)
{
	int	i;

	info->philo = malloc(sizeof(t_philo) * info->philo_num);
	if (info->philo == NULL)
		return (ft_error("Error: philo malloc"));
	i = 0;
	while (i < info->philo_num)
	{
		info->philo[i].index = i;
		info->philo[i].dead = NO;
		info->philo[i].pid = -1;
		if (info->eat_counter == -1)
			info->philo[i].eat_count = -1;
		else
			info->philo[i].eat_count = info->eat_counter;
		info->philo[i].info = info;
		i++;
	}
	return (0);
}

int	ft_info_init(int argc, char **argv, t_info *info)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->eat_counter = -1;
	info->max_eat = -1;
	info->current_eat = -1;
	if (info->philo_num <= 0 || info->time_to_die <= 0 || \
	info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (-1);
	if (argc == 6)
	{
		info->max_eat = ft_atoi(argv[5]);
		info->current_eat = 0;
		if (info->max_eat <= 0)
			return (-1);
	}
	if (ft_philo_init(info))
		return (-1);
	return (0);
}
