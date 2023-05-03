/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:10:46 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/03 22:15:32 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	ft_eat_check(t_arg *arg, t_philo *philo)
{
	int	i;

	// sem_wait(arg->eat);
	i = 0;
	while (arg->must_eat_num != 0 && i < arg->philo_num \
	&& philo[i].eat_cnt > arg->must_eat_num)
	{
		// sem_post(arg->eat);
		i++;
		// sem_wait(arg->eat);
	}
	// sem_post(arg->eat);
	// sem_wait(arg->eat);
	if (i == arg->philo_num)
		arg->eat_check = 1;
	// sem_wait(arg->eat);
}

void	ft_death_check(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	current_time;

	while (!(arg->eat_check))
	{
		i = -1;
		usleep(200);
		while ((++i < arg->philo_num))
		{
			current_time = ft_time();
			sem_wait(arg->eat);
			if ((current_time - philo[i].last_eat_time) >= arg->time_to_die)
			{
				sem_post(arg->eat);
				ft_philo_printf(arg, i, DIE);
				sem_wait(arg->sem_die);
				arg->die = 1;
				sem_post(arg->sem_die);
				return ;
			}
			sem_post(arg->eat);
		}
		ft_eat_check(arg, arg->philo);
	}
}
