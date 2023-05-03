/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:10:52 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/03 20:19:20 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_sem_init(t_arg *arg)
{
	sem_unlink("print");
	arg->print = sem_open("print", O_CREAT, 0644, 1);
	sem_unlink("forks");
	arg->forks = sem_open("forks", O_CREAT, 0644, arg->philo_num);
	sem_unlink("eat");
	arg->eat = sem_open("eat", O_CREAT, 0644, 1);
	sem_unlink("sem_die");
	arg->sem_die = sem_open("sem_die", O_CREAT, 0644, 1);
	sem_unlink("flag");
	arg->flag = sem_open("flag", O_CREAT, 0644, 1);
}

int	ft_philo_init(t_arg *arg)
{
	int	i;

	i = 0;
	arg->philo = malloc(sizeof(sem_t) * arg->philo_num);
	if (!(arg->philo))
		return (-1);
	while (i < arg->philo_num)
	{
		arg->philo[i].id = i;
		arg->philo[i].left_fork = i;
		arg->philo[i].right_fork = (i + 1) % arg->philo_num;
		arg->philo[i].eat_cnt = 0;
		arg->philo[i].last_eat_time = 0;
		arg->philo[i].arg = arg;
		i++;
	}
	return (0);
}

int	ft_arg_init(t_arg *arg, int argc, char **argv)
{
	arg->philo_num = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	arg->die = 0;
	arg->must_eat_num = 0;
	arg->start_time = ft_time();
	arg->eat_check = 0;
	if (arg->philo_num <= 0 || arg->time_to_die <= 0 || \
	arg->time_to_eat <= 0 || arg->time_to_sleep <= 0)
		return (-1);
	if (argc == 6)
	{
		arg->must_eat_num = ft_atoi(argv[5]);
		if (arg->must_eat_num <= 0)
			return (-1);
	}
	ft_sem_init(arg);
	if (ft_philo_init(arg))
		return (-1);
	return (0);
}
