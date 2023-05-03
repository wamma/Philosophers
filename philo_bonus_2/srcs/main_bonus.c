/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:10:25 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/03 16:10:27 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (ft_error("Error: argument"));
	if (ft_arg_init(&arg, argc, argv))
		return (ft_error("Error: input_arg"));
	if (ft_start_philo(&arg, arg.philo))
		return (ft_error("Error: start_philo"));
	return (0);
}
