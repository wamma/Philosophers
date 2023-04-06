/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:57:23 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/06 20:16:57 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac != 5 && ac != 6)
		return (ft_error("Argument number error"));
	if (ft_input_philo(&philo, ac, av))
		return (ft_error("Check in the right argument"));
}
