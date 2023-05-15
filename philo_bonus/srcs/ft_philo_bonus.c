/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:31:32 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/15 21:36:58 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*ft_death_check(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->info->death);
		if (philo->next_meal < ft_time())
		{
			ft_printf(DIED, philo);
			sem_post(philo->info->death);
			break ;
		}
		sem_post(philo->info->death);
		sem_wait(philo->info->death);
		if ((philo->info->eat_count != -1) && \
		(philo->info->current_eat >= philo->info->max_eat))
		{
			sem_post(philo->info->stop);
			break ;
		}
		sem_post(philo->info->death);
	}
	return (0);
}

void	ft_routine(t_philo *philo)
{
	pthread_t	sub_philo;

	philo->next_meal = ft_time() + (long long)philo->info->time_to_die;
	pthread_create(&sub_philo, NULL, ft_death_check, philo);
	pthread_detach(sub_philo);
	while (1)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_printf(THINK, philo);
	}
}

void	ft_create_process(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			ft_routine(philo + i);
			exit(0);
		}
		i++;
		usleep(100);
	}
}
