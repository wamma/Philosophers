/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:13:15 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/11 21:14:57 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_mutex_init(t_philo *philo)
{
	int	i;

	if (pthread_mutex_init(&(philo->philo), NULL))
		return (-1);
	if (pthread_mutex_init(&(philo->eat), NULL))
		return (-1);
	philo->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t *) \
	* philo->philo_num);
	if (!(philo->fork))
		return (-1);
	i = 0;
	while (i < philo->philo_num)
	{
		pthread_mutex_init(&(philo->fork[i]), NULL);
		i++;
	}
	return (0);
}

int	ft_pthread_init(t_philo *philo)
{
	int	i;

	i = 0;
	philo->info = (t_philo *)malloc(sizeof(t_philo *) * philo->philo_num);
	if (!(philo->info))
		return (-1);
	while (i < philo->philo_num)
	{
		philo->info[i].id = i;
		philo->info[i].left_fork = i;
		philo->info[i].right_fork = i;
		philo->info[i].eat_cnt = 0;
		philo->info[i].check_death_time = 0;
		i++;
	}
	return (0);
}

int	ft_input_philo(t_philo *philo, int ac, char **av)
{
	philo->philo_num = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->must_eat_num = 0;
	philo->eat_check = 0;
	philo->die = 0;
	philo->start_time = 0;
	if (ac == 6)
	{
		philo->must_eat_num = ft_atoi(av[5]);
		if (philo->must_eat_num <= 0)
			return (-1);
	}
	if (ft_mutex_init(philo))
		return (-1);
	if (ft_pthread_init(philo))
		return (-1);
	return (0);
}
