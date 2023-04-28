/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:58:52 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/28 15:16:16 by hyungjup         ###   ########.fr       */
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
# define DIE "died"

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_cnt;
	long long		last_eat_time;
	pthread_t		thread_id;
	struct s_arg	*arg;
}	t_philo;

typedef struct s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	long long		start_time;
	int				die;
	int				eat_check;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_arg;

/*philo_check.c*/
void		ft_death_check(t_arg *arg, t_philo *philo);
/*philo_init.c*/
int			ft_mutex_init(t_arg *arg);
int			ft_philo_init(t_arg *arg);
int			ft_arg_init(t_arg *arg, int ac, char **av);

/*philo_utils.c*/
int			ft_error(char *err);
void		ft_free_thread(t_arg *arg);

/*philo.c*/
int			ft_philo_do(t_arg *arg, t_philo *philo);
void		*ft_pthread(void *philo_cp);
int			ft_start_philo(t_arg *arg, t_philo *philo);

/*print.c*/
void		ft_philo_printf(t_arg *arg, int id, char *message);

/*time.c*/
long long	ft_time(void);
void		ft_time_taken(long long wait_time);

/*ft_atoi.c*/
int			ft_atoi(char *str);

#endif
