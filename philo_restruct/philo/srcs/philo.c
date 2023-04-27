/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:43:50 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/27 11:03:43 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_eat(t_info *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->eat));
	ft_philo_printf(arg, philo->id, EAT);
	philo->last_eat_time = ft_time();
	pthread_mutex_unlock(&(arg->eat));
	(philo->eat_cnt)++;
	ft_time_taken(arg, (long long)arg->time_to_eat);
}

int	ft_philo_do(t_info *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left_fork]));
	ft_philo_printf(arg, philo->id, TAKE_FORK);
	pthread_mutex_lock(&(arg->forks[philo->right_fork]));
	ft_philo_printf(arg, philo->id, TAKE_FORK);
	ft_philo_eat(philo->arg, philo);
	pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
	pthread_mutex_unlock(&(arg->forks[philo->right_fork]));
	if (arg->eat_check)
		return (-1);
	return (0);
}

void	*ft_pthread(void *philo)
{
	t_info	*arg;
	t_philo	*philo_cp;

	philo_cp = (t_philo *)philo;
	arg = philo_cp->arg;
	if (philo_cp->id % 2)
		usleep(10000);
	while (!(arg->die))
	{
		if (ft_philo_do(arg, philo_cp))
			break ;
		ft_philo_printf(arg, philo_cp->id, SLEEP);
		ft_time_taken(arg, (long long)arg->time_to_sleep);
		ft_philo_printf(arg, philo_cp->id, THINK);
	}
	return (0);
}

void	ft_free_philo(t_info *arg, t_philo *philo)
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
}

int	ft_start_philo(t_info *info)
{
	int		i;
	void	*routine;

	info->thread = malloc(sizeof(pthread_t) * info->philo_num);
	if (!(info->thread))
		return (-1);
	routine = routine;
	i = 0;
	
	return (0);
}
