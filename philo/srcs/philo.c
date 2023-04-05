/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:57:23 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/05 20:35:34 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	if ('0' <= str[i] && str[i] <= '9')
		return (0);
	else
		return (1);
}

int	ft_valid_check(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (ft_error("Please include 5 or 6 arguments"));
	if (ft_check_num(*av) == 1)
		return (ft_error("Please only put numbers in arguments"));
	return (0);
}

int	main(int ac, char **av)
{
	// t_info	*info;

	ft_valid_check(ac, av);
}
