/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:03:16 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/15 20:31:21 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
		return (printf("Error: arguments"));
	if (ft_info_init(argc, argv, &info))
		return (printf("Error: info init"));
	info.philo = ft_philo_init(&info);
	info.start = ft_time();
	ft_semaphore_init(&info);
	sem_wait(info.stop);
	ft_create_process(&info, info.philo);
	return (0);
}
