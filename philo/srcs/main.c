/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:57:23 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/14 17:50:15 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_arg	arg;

	if (ac != 5 && ac != 6)
		return (ft_error("Error: argument"));
	if (ft_input_philo(&arg, ac, av))
		return (ft_error("Error: input_philo"));
	if (ft_start_philo(&arg, &arg.philo))
		return (ft_error("Error: start_philo"));
	return (0);
}
