/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:47:56 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/05 19:51:35 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_philo_printf(t_philo *philo, char *message)
{
	long long	current_time;

	current_time = ft_time();
	sem_wait(philo->info->print);
	printf("%lld %d %s\n", current_time - philo->info->start_time, \
	philo->id + 1, message);
	sem_post(philo->info->print);
}
