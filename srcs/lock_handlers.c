/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:44:53 by ncarrera          #+#    #+#             */
/*   Updated: 2025/10/12 16:31:50 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philos *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->left_fork);
		printf("%lld %d has taken a fork\n", e_time(p->data->sim_time), p->id);
		pthread_mutex_lock(p->right_fork);
		printf("%lld %d has taken a fork\n", e_time(p->data->sim_time), p->id);
	}
	else
	{
		pthread_mutex_lock(p->right_fork);
		printf("%lld %d has taken a fork\n", e_time(p->data->sim_time), p->id);
		pthread_mutex_lock(p->left_fork);
		printf("%lld %d has taken a fork\n", e_time(p->data->sim_time), p->id);
	}
}

void	unlock_forks(t_philos *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
