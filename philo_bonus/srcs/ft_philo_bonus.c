/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:31:32 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/15 20:42:18 by hyungjup         ###   ########.fr       */
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
			ft_print(DIED, philo);
			sem_post(philo->info->death);
			break ;
		}
		sem_post(philo->info->death);
		sem_wait(philo->info->death);
		if ()
	}
}

void	ft_routine(t_philo *philo)
{
	pthread_t	sub_philo;

	philo->next_meal = ft_time() + (long long)philo->info->time_to_die;
	pthread_create(&sub_philo, NULL, ft_death_check, philo);
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
