/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:43:44 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/21 16:13:03 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(char *err)
{
	printf("%s\n", err);
	return (1);
}

void	ft_free_thread(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_num)
		pthread_mutex_destroy(&(arg->forks[i++]));
	free(arg->forks);
	free(arg->philo);
	pthread_mutex_destroy(&(arg->print));
}
