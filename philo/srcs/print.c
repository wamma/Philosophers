/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:47:56 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/02 17:26:46 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_printf(t_arg *arg, int id, char *message)
{
	long long	current_time;

	pthread_mutex_lock(&(arg->print));
	current_time = ft_time();
	pthread_mutex_lock(&(arg->die_mutex));
	if (!(arg->die))
		printf("%lld %d %s\n", current_time - arg->start_time, id + 1, message);
	pthread_mutex_unlock(&(arg->die_mutex));
	pthread_mutex_unlock(&(arg->print));
	return ;
}
