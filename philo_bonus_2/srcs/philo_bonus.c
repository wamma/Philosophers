/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:10:39 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/03 20:23:35 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_philo_eat(t_arg *arg, t_philo *philo)
{
	ft_philo_printf(arg, philo->id, EAT);
	philo->last_eat_time = ft_time();
	(philo->eat_cnt)++;
	ft_time_taken((long long)arg->time_to_eat);
}

int	ft_philo_do(t_arg *arg, t_philo *philo)
{
	// sem_wait(arg->sem_die);
	ft_philo_printf(arg, philo->id, TAKE_FORK);
	sem_wait(arg->forks);
	if (arg->philo_num == 1)
	{
		ft_time_taken((long long)arg->time_to_die);
		return (0);
	}
	ft_philo_printf(arg, philo->id, TAKE_FORK);
	sem_wait(arg->forks);
	ft_philo_eat(philo->arg, philo);
	sem_post(arg->forks);
	sem_post(arg->forks);
	// sem_wait(arg->eat);
	if (arg->eat_check)
	{
		// sem_post(arg->eat);
		return (-1);
	}
	// sem_post(arg->eat);
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
	sem_wait(arg->sem_die);
	while (!(arg->die))
	{
		sem_post(arg->sem_die);
		if (ft_philo_do(arg, philo_cp))
			break ;
		ft_philo_printf(arg, philo_cp->id, SLEEP);
		ft_time_taken((long long)arg->time_to_sleep);
		ft_philo_printf(arg, philo_cp->id, THINK);
		usleep(100);
		sem_wait(arg->sem_die);
	}
	sem_post(arg->sem_die);
	return (0);
}

// void	ft_free_philo(t_arg *arg, t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	while (i < arg->philo_num)
// 		pthread_join(philo[i++].thread_id, NULL);
// 	i = 0;
// 	while (i < arg->philo_num)
// 		sem_unlink(&(arg->forks[i++]));
// 	free(arg->philo);
// 	free(arg->forks);
// 	pthread_mutex_destroy(&(arg->print));
// 	pthread_mutex_destroy(&(arg->eat));
// 	pthread_mutex_destroy(&(arg->die_mutex));
// }

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
	// ft_free_philo(arg, arg->philo);
	return (0);
}
