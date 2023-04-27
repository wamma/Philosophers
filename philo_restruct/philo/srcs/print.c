/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:47:56 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/27 12:40:46 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_printf(t_info *info, int id, char *message)
{
	long long	current_time;

	current_time = ft_time();
	pthread_mutex_lock(&(info->print));
	if (!(info->die))
		printf("%lld %d %s \n", current_time - info->start_time, id + 1, message);
	pthread_mutex_unlock(&(info->print));
	return ;
}

int	print_fork(t_philo *philo)
{
	long long		current_time;
	long long		time_stamp;

	current_time = ft_time();
	time_stamp = current_time - philo->info->start_time;
}