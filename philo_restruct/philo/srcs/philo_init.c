/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:13:15 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/26 21:29:10 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_fork_init(t_info *info)
{
	int	i;

	info->fork = malloc(sizeof(int) * info->philo_num);
	if (!(info->fork))
	{
		free_philo(info);
		return (-1);
	}
	i = 0;
	while (i < info->philo_num)
	{
		info->fork[i] = 0;
		i++;
	}
	return (0);
}

int	ft_fork_mutex_init(t_info *info)
{
	int	i;

	info->fork_mutex = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (!(info->fork_mutex))
	{
		free_philo(info);
		free(info->fork);
		return (-1);
	}
	i = -1;
	while (++i < info->philo_num)
	{
		if (pthread_mutex_init(&(info->fork_mutex[i]), NULL))
		{
			free_philo(info);
			free_fork(info);
			return (-1);
		}
	}
	return (0);
}

int	ft_philo_init(t_info *info)
{
	int	i;

	info->philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!(info->philo))
		return (-1);
	i = -1;
	while (++i < info->philo_num)
	{
		info->philo[i].id = i;
		if (pthread_mutex_init(&(info->philo[i].last_eat_time_mutex), NULL))
			return (-1);
		if (pthread_mutex_init(&(info->philo[i].eat_cnt_mutex), NULL))
			return (-1);
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % info->philo_num;
		if (i % 2 == 1)
			swap_fork(&(info->philo[i]));
		info->philo[i].eat_cnt = 0;
		info->philo[i].last_eat_time = 0;
		info->philo[i].info = info;
	}
	return (0);
}

int	ft_info_init(t_info *info, int argc, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->must_eat_flag = 0;
	info->start_time = 0;
	info->finish_flag = 0;
	if (info->philo_num <= 0 || info->time_to_die <= 0 || \
	info->time_to_eat < 0 || info->time_to_sleep < 0)
		return (-1);
	if (argc == 6)
	{
		info->must_eat_flag = 1;
		info->must_eat = ft_atoi(argv[5]);
		if (info->must_eat <= 0)
			return (-1);
	}
	if (ft_philo_init(info))
		return (-1);
	if (ft_fork_init(info))
		return (-1);
	if (ft_fork_mutex_init(info))
		return (-1);
	if (ft_mutex_init(info))
		return (-1);
	return (0);
}
