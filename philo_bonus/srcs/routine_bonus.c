/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:08:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/04 20:39:28 by hyungjup         ###   ########.fr       */
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
	long long	current_time;

	sem_wait(philo->sem_last_eat_time);
	current_time = ft_time();
	philo->last_eat_time = current_time - philo->info->start_time;
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

void	routine(t_info *info, int i)
{
	pthread_t	sub_info;

	ft_philo_init(info, info->philo, i);
	sem_wait(info->sem_start);
	sem_post(info->sem_start);
	if (pthread_create(sub_info, NULL, ft_philo_monitor, &(info->philo[i])))
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
