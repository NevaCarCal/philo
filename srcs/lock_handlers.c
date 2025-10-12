/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:44:53 by ncarrera          #+#    #+#             */
/*   Updated: 2025/10/08 21:50:02 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	e_time(long long sim_time)
{
	return (get_time() - sim_time);
}

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

void	precise_usleep(long long milliseconds_to_sleep)
{
	long long	start_time;
	long long	end_time;

	start_time = get_time();
	end_time = start_time + milliseconds_to_sleep;
	while (get_time() < end_time)
		usleep(10);
}
