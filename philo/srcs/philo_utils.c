/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:43:44 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/26 19:22:56 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(char *err)
{
	printf("%s\n", err);
	return (1);
}

void	ft_free_thread(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_num)
		pthread_mutex_destroy(&(arg->forks[i++]));
	free(arg->forks);
	free(arg->philo);
	pthread_mutex_destroy(&(arg->print));
}

void	swap_fork(t_philo *philo)
{
	int	tmp;

	tmp = philo->left_fork;
	philo->left_fork = philo->right_fork;
	philo->right_fork = tmp;
}

int	ft_monitoring(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < arg->philo_num)
	{
		
	}
}
