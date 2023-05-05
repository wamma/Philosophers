/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:08:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/05 19:59:59 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->info->fork);
	ft_philo_printf(philo, "has taken a fork");
	sem_wait(philo->info->fork);
	ft_philo_printf(philo, "has taken a fork");
}

static void	ft_eat(t_philo *philo)
{
	sem_wait(philo->sem_last_eat_time);
	philo->last_eat_time = ft_time();
	sem_post(philo->sem_last_eat_time);
	ft_philo_printf(philo, "is eating");
	ft_time_taken((long long)philo->info->time_to_eat);
	sem_wait(philo->sem_eat_count);
	(philo->eat_count)++;
	sem_post(philo->sem_eat_count);
}

static void	ft_take_off_fork(t_philo *philo)
{
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
	return ;
}

static void	ft_sleep(t_philo *philo)
{
	ft_philo_printf(philo, "is sleeping");
	ft_time_taken((long long)philo->info->time_to_sleep);
}

int	routine(t_info *info, int i)
{
	pthread_t	sub_info;

	ft_philo_init(info, &(info->philo[i]), i);
	if (pthread_create(&sub_info, NULL, ft_philo_monitor, \
	&(info->philo[i])) != 0)
		return (-1);
	if (info->philo[i].id % 2 == 1)
		usleep(info->time_to_eat * 1000);
	while (1)
	{
		ft_take_fork(&(info->philo[i]));
		ft_eat(&(info->philo[i]));
		ft_take_off_fork(&(info->philo[i]));
		ft_sleep(&(info->philo[i]));
		ft_philo_printf(&(info->philo[i]), "is thinking");
		usleep(100);
	}
}
