/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:58:52 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/05 20:39:34 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int			id;
	int			left_fork;
	int			right_fork;
	int			eat_cnt;
	pthread_t	thread_id;
}	t_philo;

typedef struct s_info
{
	int		philo_num;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat_num;
	int		start;
	int		die;
	t_philo	*philo;
}	t_info;

int	ft_check_valid(int ac, char **av);
int	ft_error(char *err);

#endif