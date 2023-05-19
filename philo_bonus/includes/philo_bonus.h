/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:04:21 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/18 15:41:09 by hyungjup         ###   ########.fr       */
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
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIED 5

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
	int				eat_counter;
	int				max_eat;
	int				current_eat;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*death;
	sem_t			*stop;
	t_philo			*philo;
}	t_info;

/*ft_init_bonus.c*/
void		ft_semaphore_init(t_info *info);
int			ft_philo_init(t_info *info);
int			ft_info_init(int argc, char **argv, t_info *info);
void		*ft_death_check(void *arg);
void		ft_routine(t_philo *philo);
void		ft_create_process(t_info *info, t_philo *philo);

/*ft_print_bonus.c*/
void		ft_printf(int status, t_philo *philo);

/*ft_time.c*/
long long	ft_time(void);

/*ft_utils_bonus.c*/
int			ft_error(char *err);
int			ft_atoi(char *str);
void		ft_destory_process(t_info *info, t_philo *philo);

/*ft_routine_bonus.c*/
void		ft_take_fork(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);

#endif