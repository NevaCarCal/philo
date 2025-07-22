/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:12:18 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/22 02:18:05 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_data_philos
{
	int	philnum;
	int	dietime;
	int	eattime;
	int	sleeptime;
	int	maxeatnum;
}				t_data_philos;
typedef struct s_philos
{
	void			*philo;
	void			*fork;
	struct s_philos	*right;
	struct s_philos	*left;
}				t_philos;
int		ft_ispnumstr(char *str);
int		ft_atoi(const char *nptr);
int		init_checks(t_data_philos *data, int argc, char **argv);

#endif
