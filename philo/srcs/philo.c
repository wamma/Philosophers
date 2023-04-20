/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:43:50 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/20 20:15:44 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_philo_printf(t_arg *arg, int id, char *message)
{
	long long	current_time;

	current_time = ft_time();
	pthread_mutex_lock(&(arg->print));
	if (!(arg->die))
		printf("%lld %d %s \n", current_time - arg->start_time, id + 1, message);
	return (0);
}

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
	pthread_mutex_unlock(&(arg->forks[philo->right_fork]));
	return (0);
}

void	*ft_pthread(void *philo_cp)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = philo_cp;
	arg = philo->arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!arg->die)
	{
		ft_philo_do(arg, philo);
		if (arg->must_eat_num == philo->eat_cnt)
		{
			arg->finish_eat++;
			break ;
		}
		ft_philo_printf(arg, philo->id, "is sleeping");
		ft_time_taken(arg, (long long)arg->time_to_sleep);
		ft_philo_printf(arg, philo->id, "is thinking");
	}
	return (0);
}

int	ft_start_philo(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	arg->start_time = ft_time();
	while (i < arg->philo_num)
	{
		philo[i].check_death_time = ft_time();
		if (pthread_create(&(philo[i].thread_id), NULL, \
		ft_pthread, &(philo[i])))
			return (1);
		i++;
	}
	ft_death_check(arg, philo);
	return (0);
}
