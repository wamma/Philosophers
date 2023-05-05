/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:04:21 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/05 21:14:03 by hyungjup         ###   ########.fr       */
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

typedef struct s_philo
{
	pid_t			pid;
	int				id;
	long long		last_eat_time;
	sem_t			*sem_last_eat_time;
	int				eat_count;
	sem_t			*sem_eat_count;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				must_eat_flag;
	int				die;
	int				eat_check;
	struct timeval	start_time;
	sem_t			*sem_start;
	sem_t			*sem_finish;
	sem_t			*sem_full;
	sem_t			*fork;
	sem_t			*print;
	t_philo			*philo;
}	t_info;

/*free_bonus.c*/
void		kill_process(t_info *info);
void		free_info(void);

/*death_check_bonus.c*/
int			ft_death_check(t_philo *philo);

/*info_bonus.c*/
void		*ft_philo_monitor(void *arg);
void		*ft_pthread(void *arg);
int			info_start(t_info *info);

/*philo_init_bonus.c*/
void		ft_semaphore_init(t_info *info);
int			ft_philo_init(t_info *info, t_philo *philo, int i);
int			ft_info_init(t_info *info, int argc, char **argv);

/*philo_utils_bonus.c*/
int			ft_error(char *err);
int			ft_atoi(char *str);

/*print_bonus.c*/
void		ft_philo_printf(t_philo *philo, char *message);

/*routine_bonus.c*/
int			routine(t_info *info, int i);

/*time.c*/
long long	ft_time(void);
void		ft_time_taken(long long wait_time);

#endif