/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:43:44 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/26 19:39:59 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(char *err)
{
	printf("%s\n", err);
	return (1);
}

void	ft_free_thread(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
		pthread_mutex_destroy(&(info->fork[i++]));
	free(info->fork);
	free(info->philo);
	pthread_mutex_destroy(&(info->print));
}

void	swap_fork(t_philo *philo)
{
	int	tmp;

	tmp = philo->left_fork;
	philo->left_fork = philo->right_fork;
	philo->right_fork = tmp;
}

int	ft_monitoring(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		
	}
}
