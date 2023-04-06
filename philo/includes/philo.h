/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:58:52 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/06 21:11:01 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_info
{
	int		id;
	int		left_fork;
	int		right_fork;
	int		eat_cnt;
}	t_info;

typedef struct s_philo
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	int				start_time;
	int				die;
	int				eat_check;
	pthread_t		thread_id;
	t_info			*info;
	pthread_mutex_t	write;
	pthread_mutex_t	eat;
	pthread_mutex_t	*fork;
}	t_philo;

int	ft_error(char *err);
int	ft_atoi(const char *str);
int	ft_input_philo(t_philo *philo, int ac, char **av);
int	ft_mutex_init(t_philo *philo);

#endif