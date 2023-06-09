/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:43:50 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/02 20:50:50 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_eat(t_arg *arg, t_philo *philo)
{
	ft_philo_printf(arg, philo->id, EAT);
	pthread_mutex_lock(&(arg->eat));
	philo->last_eat_time = ft_time();
	(philo->eat_cnt)++;
	pthread_mutex_unlock(&(arg->eat));
	ft_time_taken((long long)arg->time_to_eat);
}

int	ft_philo_do(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left_fork]));
	ft_philo_printf(arg, philo->id, TAKE_FORK);
	if (arg->philo_num == 1)
	{
		ft_time_taken((long long)arg->time_to_die);
		return (0);
	}
	pthread_mutex_lock(&(arg->forks[philo->right_fork]));
	ft_philo_printf(arg, philo->id, TAKE_FORK);
	ft_philo_eat(philo->arg, philo);
	pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
	pthread_mutex_unlock(&(arg->forks[philo->right_fork]));
	pthread_mutex_lock(&(arg->eat));
	if (arg->eat_check)
	{
		pthread_mutex_unlock(&(arg->eat));
		return (-1);
	}
	pthread_mutex_unlock(&(arg->eat));
	return (0);
}

void	*ft_pthread(void *philo)
{
	t_arg	*arg;
	t_philo	*philo_cp;

	philo_cp = (t_philo *)philo;
	arg = philo_cp->arg;
	if (philo_cp->id % 2)
		usleep(arg->time_to_eat * 1000);
	pthread_mutex_lock(&(arg->die_mutex));
	while (!(arg->die))
	{
		pthread_mutex_unlock(&(arg->die_mutex));
		if (ft_philo_do(arg, philo_cp))
			break ;
		ft_philo_printf(arg, philo_cp->id, SLEEP);
		ft_time_taken((long long)arg->time_to_sleep);
		ft_philo_printf(arg, philo_cp->id, THINK);
		usleep(100);
		pthread_mutex_lock(&(arg->die_mutex));
	}
	pthread_mutex_unlock(&(arg->die_mutex));
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
	pthread_mutex_destroy(&(arg->eat));
	pthread_mutex_destroy(&(arg->die_mutex));
}

int	ft_start_philo(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	arg->start_time = ft_time();
	while (i < arg->philo_num)
	{
		philo[i].last_eat_time = ft_time();
		if (pthread_create(&(philo[i].thread_id), NULL, \
		ft_pthread, (void *)&(philo[i])))
			return (-1);
		i++;
	}
	ft_death_check(arg, arg->philo);
	ft_free_philo(arg, arg->philo);
	return (0);
}
