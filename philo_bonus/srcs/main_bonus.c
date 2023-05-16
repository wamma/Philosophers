/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:03:16 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/16 15:54:55 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
		return (ft_error("Error: arguments"));
	if (ft_info_init(argc, argv, &info))
		return (ft_error("Error: info init"));
	if (ft_philo_init(&info))
		return (ft_error("Error: philo init"));
	info.start = ft_time();
	ft_semaphore_init(&info);
	sem_wait(info.stop);
	ft_create_process(&info, info.philo);
	sem_wait(info.stop);
	ft_destory_process(&info, info.philo);
	return (0);
}
