/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:04:05 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/28 19:36:55 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	ft_philo_generate(t_info *info)
{
	int	i;

	sem_wait(info->sem_start);
	i = 0;
	while (i < info->philo_num)
	{
		info->philo[i].pid = fork();
		if (info->philo[i].pid < 0)
			break ;
		if (info->philo[i].pid == 0)
		{
			routine(info, i);
			return (0);
		}
		i++;
	}
	sem_post(info->sem_start);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 || argc != 6)
		return (ft_error("Error: argument"));
	if (ft_info_init(&info, argc, argv))
		return (ft_error("Error: info error"));
	if (ft_philo_generate(&info))
	{
		sem_wait(info.print);
		ft_error("Error: philo generate");
		sem_post(info.sem_finish);
	}
	info_start(&info, info.philo);
	return (0);
}
