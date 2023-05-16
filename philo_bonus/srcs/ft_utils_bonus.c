/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:34:32 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/16 15:48:41 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_error(char *err)
{
	printf("%s\n", err);
	return (-1);
}

void	ft_destory_process(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
		kill(philo[i++].pid, SIGKILL);
	sem_close(info->stop);
	sem_close(info->death);
	sem_close(info->print);
	sem_close(info->forks);
	free(philo);
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
