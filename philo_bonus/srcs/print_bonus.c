/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:47:56 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/04 19:48:01 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_philo_printf(t_philo *philo, char *message)
{
	long long	current_time;

	sem_wait(philo->info->print);
	current_time = ft_time();
	printf("%lld %d %s\n", current_time - philo->info->start_time, \
	philo->id + 1, message);
	sem_post(philo->info->print);
}
