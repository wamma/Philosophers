/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:04:21 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/28 20:45:45 by hyungjup         ###   ########.fr       */
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

# define DIE 1
# define FULL 2

typedef struct s_philo
{
	pid_t			pid;
	int				id;
	int				eat_count;
	long long		last_eat_time;
	sem_t			*sem_last_eat_time;
	pthread_t		thread_id;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	int			must_eat_flag;
	int			die;
	int			eat_check;
	long long	start_time;
	sem_t		*sem_start;
	sem_t		*sem_finish;
	sem_t		*sem_full;
	sem_t		*fork;
	sem_t		*print;
	t_philo		*philo;
}	t_info;

/*philo_utils_bonus.c*/
int			ft_error(char *err);
int			ft_atoi(char *str);

/*info_bonus.c*/
int			info_start(t_info *info, t_philo *philo);

/*time.c*/
long long	ft_time(void);
void		ft_time_taken(long long wait_time);

#endif