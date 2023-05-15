/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:34:32 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/15 21:59:26 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_error(char *err)
{
	printf("%s\n", err);
	return (-1);
}

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

void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->info->forks);
	ft_printf(FORK, philo);
	sem_wait(philo->info->forks);
	ft_printf(FORK, philo);
}

void	ft_eat(t_philo *philo)
{
	ft_printf(EAT, philo);
	if (philo->info->eat_count != -1)
		philo->info->current_eat++;
	usleep(philo->info->time_to_eat * 1000);
	philo->eating_time = ft_time();
	philo->next_meal = philo->eating_time + (long long)philo->info->time_to_die;
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}

void	ft_sleep(t_philo *philo)
{
	ft_printf(SLEEP, philo);
	usleep(philo->info->time_to_sleep * 1000);
}
