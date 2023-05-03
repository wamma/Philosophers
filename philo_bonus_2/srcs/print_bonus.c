/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:11:00 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/03 22:21:51 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_philo_printf(t_arg *arg, int id, char *message)
{
	long long	current_time;

	// sem_wait(arg->print);
	current_time = ft_time();
	// sem_wait(arg->sem_die);
	if (!(arg->die))
		printf("%lld %d %s\n", current_time - arg->start_time, id + 1, message);
	// sem_post(arg->sem_die);
	// sem_post(arg->print);
	return ;
}
