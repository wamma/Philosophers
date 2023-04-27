/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:58:52 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/27 20:22:22 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TAKE_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "is died"

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_cnt;
	pthread_mutex_t	eat_cnt_mutex;
	long long		last_eat_time;
	pthread_mutex_t	last_eat_time_mutex;
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
	int				finish_flag;
	int				*fork;
	pthread_mutex_t	*fork_mutex;
	pthread_t		*thread;
	pthread_mutex_t	mutex_start;
	pthread_mutex_t	mutex_finish;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	t_philo			*philo;
}	t_info;

/*philo_check.c*/
void		ft_death_check(t_info *arg, t_philo *philo);
/*philo_init.c*/
int			ft_mutex_init(t_info *arg);
int			ft_philo_init(t_info *arg);
int			ft_info_init(t_info *arg, int ac, char **av);

/*philo_utils.c*/
int			ft_error(char *err);
void		ft_free_thread(t_info *arg);

/*philo.c*/
int			ft_philo_do(t_info *arg, t_philo *philo);
void		*ft_pthread(void *philo_cp);
int			ft_start_philo(t_info *arg, t_philo *philo);

/*print.c*/
void		ft_philo_printf(t_info *info, int id, char *message);

/*time.c*/
long long	ft_time(void);
void		ft_time_taken(t_info *arg, long long wait_time);

/*ft_atoi.c*/
int			ft_atoi(char *str);

/*free.c*/
int			free_philo(t_info *info);
void		free_fork(t_info *info);

/*setting.c*/
int			ft_setting_mutex(t_info *info);

#endif
