/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:43:50 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/11 21:40:06 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_pthread(void *philo)
{
	t_philo	*t_philo;
	t_info	*tmp_philo;

	tmp_philo = (t_info)t_philo;
	t_philo = tmp_philo->philo;
	if (tmp_philo->id % 2)
		usleep(10000);
	return (0);
}

int	ft_start_philo(t_philo *philo)
{
	int		i;
	void	*tmp_philo;

	i = 0;
	philo->start_time = ft_time();
	while (i < philo->philo_num)
	{
		philo->info[i].check_death_time = ft_time();
		tmp_philo = (void *)&(philo->info[i]);
		if (pthread_create(&(philo->info[i].thread_id), NULL, \
			ft_pthread, tmp_philo))
			return (-1);
		i++;
	}
	죽었는지 체크
}
