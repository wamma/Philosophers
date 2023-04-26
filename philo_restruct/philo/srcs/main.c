/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:57:23 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/26 19:30:31 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
		return (ft_error("Error: argument"));
	if (ft_info_init(&info, argc, argv))
		return (ft_error("Error: input_info"));
	if (ft_start_philo(&info, info.philo))
		return (ft_error("Error: start_philo"));
	return (0);
}
