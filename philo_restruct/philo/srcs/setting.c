/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:57:31 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/27 10:59:43 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_setting_mutex(t_info *info)
{
	if (pthread_mutex_init(&(info->mutex_start), NULL))
		return (-1);
	if (pthread_mutex_init(&(info->mutex_finish), NULL))
	{
		pthread_mutex_destroy(&(info->mutex_start), NULL);
		return (-1);
	}
	return (0);
}
