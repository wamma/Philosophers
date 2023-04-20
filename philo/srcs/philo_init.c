/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:13:15 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/20 20:15:39 by hyungjup         ###   ########.fr       */
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
	arg->philo = (t_philo *)malloc(sizeof(t_philo *) * arg->philo_num);
	if (!(arg->philo))
		return (1);
	while (i < arg->philo_num)
	{
		arg->philo[i].arg = arg;
		arg->philo[i].id = i + 1;
		arg->philo[i].left_fork = i;
		arg->philo[i].right_fork = (i + 1) % arg->philo_num;
		arg->philo[i].eat_cnt = 0;
		arg->philo[i].check_death_time = ft_time();
		i++;
	}
	return (0);
}

int	ft_init_arg(t_arg *arg, int argc, char **argv)
{
	arg->philo_num = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	arg->die = 0;
	arg->start_time = ft_time();
	if (arg->philo_num <= 0 || arg->time_to_die < 0 || \
	arg->time_to_eat < 0 || arg->time_to_sleep < 0)
		return (1);
	if (argc == 6)
	{
		arg->must_eat_num = ft_atoi(argv[5]);
		if (arg->must_eat_num <= 0)
			return (1);
	}
	if (ft_mutex_init(arg))
		return (1);
	if (ft_philo_init(arg))
		return (1);
	return (0);
}
