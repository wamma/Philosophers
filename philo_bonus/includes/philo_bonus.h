/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:04:21 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/15 17:35:08 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

# define YES 1
# define NO 0
# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5
# define DONE 6

typedef struct s_philo
{
	pid_t			pid;
	long long		eating_time;
	long long		next_meal;
	int				index;
	int				dead;
	int				eat_count;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	long long		start;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;
	int				max_eat;
	int				current_eat;
	sem_t			*forks;
	sem_t			*message;
	sem_t			*death;
	sem_t			*stop;
	t_philo			*philo;
}	t_info;

#endif