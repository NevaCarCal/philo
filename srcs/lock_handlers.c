/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:44:53 by ncarrera          #+#    #+#             */
/*   Updated: 2025/10/12 16:17:35 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philos *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->left_fork);
		print_queue(p, "has taken a fork\n");
		pthread_mutex_lock(p->right_fork);
		print_queue(p, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(p->right_fork);
		print_queue(p, "has taken a fork\n");
		pthread_mutex_lock(p->left_fork);
		print_queue(p, "has taken a fork\n");
	}
}

void	unlock_forks(t_philos *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	print_queue(t_philos *philo, const char *message)
{
	pthread_mutex_lock(&philo->data->data_lock);
	if (!philo->data->death_signal)
	{
		printf("%lld %d %s", e_time(philo->data->sim_time),
			philo->id, message);
	}
	pthread_mutex_unlock(&philo->data->data_lock);
}
