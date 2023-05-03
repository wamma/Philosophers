/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:11:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/03 16:11:06 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

long long	ft_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	ft_time_taken(long long wait_time)
{
	long long	start_time;
	long long	current_time;

	start_time = ft_time();
	while (1)
	{
		current_time = ft_time();
		if ((current_time - start_time) >= wait_time)
			break ;
		usleep(100);
	}
}
