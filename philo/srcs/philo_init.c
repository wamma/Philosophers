/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:13:15 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/14 19:11:56 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_mutex_init(t_arg *arg)
{
	int	i;

	if (pthread_mutex_init(&(arg->print), NULL))
		return (1);
	arg->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t *) \
	* arg->philo_num);
	if (!(arg->forks))
		return (1);
	i = 0;
	while (i < arg->philo_num)
	{
		if (pthread_mutex_init(&(arg->forks[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_philo_init(t_arg *arg)
{
	int	i;

	i = 0;
	arg->philo = (t_arg *)malloc(sizeof(t_arg *) * arg->philo_num);
	if (!(arg->philo))
		return (1);
	while (i < arg->philo_num)
	{
		arg->philo[i].arg = arg;
		arg->philo[i].id = i;
		arg->philo[i].left_fork = i;
		arg->philo[i].right_fork = (i + 1) % arg->philo_num;
		arg->philo[i].eat_cnt = 0;
		arg->philo[i].check_death_time = 0;
		arg->philo[i].check_death_time = ft_time();
		i++;
	}
	return (0);
}

int	ft_input_arg(t_arg *arg, int ac, char **av)
{
	arg->philo_num = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	arg->eat_check = 0;
	arg->die = 0;
	arg->start_time = 0;
	if (ac == 6)
	{
		arg->must_eat_num = ft_atoi(av[5]);
		if (arg->must_eat_num <= 0)
			return (1);
	}
	if (ft_mutex_init(arg))
		return (1);
	if (ft_philo_init(arg))
		return (1);
	return (0);
}
