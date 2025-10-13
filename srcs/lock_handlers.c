/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:44:53 by ncarrera          #+#    #+#             */
/*   Updated: 2025/10/13 11:33:14 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philos *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->left_fork);
		print_queue(p, "has taken a fork");
		pthread_mutex_lock(p->right_fork);
		print_queue(p, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(p->right_fork);
		print_queue(p, "has taken a fork");
		pthread_mutex_lock(p->left_fork);
		print_queue(p, "has taken a fork");
	}
}

void	unlock_forks(t_philos *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
