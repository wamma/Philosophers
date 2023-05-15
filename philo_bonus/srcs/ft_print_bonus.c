/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:25:14 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/15 22:06:25 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_printf(int status, t_philo *philo)
{
	long long	time;

	time = ft_time() - philo->info->start;
	sem_wait(philo->info->print);
	if (status == FORK)
		printf("%lld %d has taken a fork", time, philo->index + 1);
	else if (status == EAT)
		printf("%lld %d is eating", time, philo->index + 1);
	else if (status == SLEEP)
		printf("%lld %d is sleeping", time, philo->index + 1);
	else if (status == THINK)
		printf("%lld %d is sleeping", time, philo->index + 1);
	else if (status == DIED)
		printf("%lld %d died", time, philo->index + 1);
	if (status != DIED)
		sem_post(philo->info->death);
}
