/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heongjunpark <heongjunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:08:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/30 22:08:47 by heongjunpar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	routine(t_info *info, int i)
{
	ft_philo_init(info);
	sem_wait(info->sem_start);
	sem_post(info->sem_start);
}
