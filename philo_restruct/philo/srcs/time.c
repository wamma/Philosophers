/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:32:35 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/25 21:25:04 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	ft_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	ft_time_taken(t_arg *arg, long long wait_time)
{
	long long	start_time;
	long long	current_time;

	start_time = ft_time();
	while (!(arg->die))
	{
		current_time = ft_time();
		if ((current_time - start_time) >= wait_time)
			break ;
		usleep(10);
	}
}
