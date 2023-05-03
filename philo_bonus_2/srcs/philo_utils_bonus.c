/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:10:56 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/03 17:01:01 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_error(char *err)
{
	printf("%s\n", err);
	return (-1);
}

// void	ft_free_thread(t_arg *arg)
// {
// 	int	i;

// 	i = 0;
// 	while (i < arg->philo_num)
// 		sem_unlink(&(arg->forks[i++]));
// 	sem_unlink("sem_start");
// }

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign *= -1;
			str++;
		}
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
