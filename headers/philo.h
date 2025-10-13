/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:12:18 by ncarrera          #+#    #+#             */
/*   Updated: 2025/10/12 16:31:56 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

struct	s_data_philos;

typedef struct s_philos
{
	struct s_data_philos	*data;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	pthread_t				thread;
	long long				last_eat_time;
	int						times_eaten;
	int						id;
}				t_philos;
typedef struct s_data_philos
{
	pthread_mutex_t	data_lock;
	pthread_mutex_t	*forks;
	long long		sim_time;
	t_philos		*philos;
	int				death_signal;
	int				max_eat_num;
	int				phil_num;
	int				sleep_time;
	int				die_time;
	int				eat_time;
}				t_data_philos;
long long	get_time(void);
void		ft_printerr(const char *msg);
int			ft_ispnumstr(char *str);
int			ft_atoi(const char *nptr);
int			init_checks(t_data_philos *data, int argc, char **argv);
int			init_data(t_data_philos *data);
void		*philo_routine(void *arg);
void		*watcher_routine(void	*arg);
long long	e_time(long long sim_time);
long long	get_time(void);
void		lock_forks(t_philos *p);
void		unlock_forks(t_philos *philo);
void		precise_usleep(long long milliseconds_to_sleep);
void		philo_cleanup(t_data_philos *data);

#endif
