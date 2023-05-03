/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:15:35 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/03 15:48:52 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_death_check(t_info *info, t_philo *philo)
{
	long long	gap_time;
	long long	current_time;

	sem_wait(philo->sem_last_eat_time);
	current_time = ft_time();
	gap_time = 
}
