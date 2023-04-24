/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:43:50 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/24 21:58:29 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_philo_do(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left_fork]));
	ft_philo_printf(arg, philo->id, "has taken a fork");
	if (arg->philo_num != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->right_fork]));
		ft_philo_printf(arg, philo->id, "has taken a fork");
		ft_philo_printf(arg, philo->id, "is eating");
		philo->last_eat_time = ft_time();
		philo->eat_cnt++;
		ft_time_taken(arg, (long long)arg->time_to_eat);
		pthread_mutex_unlock(&(arg->forks[philo->right_fork]));
	}
	if (arg->eat_check)
		return (1);
	return (0);
}

void	*ft_pthread(void *tmp)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = tmp;
	arg = philo->arg;
	if (philo->id % 2 == 0)
		usleep(10000);
	while (!arg->die)
	{
		if (ft_philo_do(arg, philo))
			break ;
		// if (arg->must_eat_num == philo->eat_cnt)
		// {
		// 	arg->must_eat_num++;
		// 	break ;
		// }
		ft_philo_printf(arg, philo->id, "is sleeping");
		ft_time_taken(arg, (long long)arg->time_to_sleep);
		ft_philo_printf(arg, philo->id, "is thinking");
	}
	return (0);
}

void	ft_free_philo(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < arg->philo_num)
		pthread_join(philo[i++].thread_id, NULL);
	i = 0;
	while (i < arg->philo_num)
		pthread_mutex_destroy(&(arg->forks[i++]));
	free(arg->philo);
	free(arg->forks);
	pthread_mutex_destroy(&(arg->print));
}

int	ft_start_philo(t_arg *arg, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < arg->philo_num)
	{
		philo[i].last_eat_time = ft_time();
		if (pthread_create(&(philo[i].thread_id), NULL, \
		ft_pthread, &(philo[i])))
			return (1);
		i++;
	}
	ft_death_check(arg, arg->philo);
	ft_free_philo(arg, arg->philo);
	return (0);
}
