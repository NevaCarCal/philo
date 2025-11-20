/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:50:06 by ncarrera          #+#    #+#             */
/*   Updated: 2025/11/20 21:21:10 by ncarrera         ###   ########.fr       */
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

void	precise_usleep(long long milliseconds_to_sleep)
{
	long long	start_time;
	long long	end_time;

	start_time = get_time();
	end_time = start_time + milliseconds_to_sleep;
	while (get_time() < end_time)
		usleep(200);
}

void	philo_sleep(long long ms_to_sleep, t_data_philos *data)
{
	long long	start_time;
	long long	end_time;

	start_time = get_time();
	end_time = start_time + ms_to_sleep;
	while (get_time() < end_time)
	{
		usleep(500);
		if (is_sim_done(data))
			return ;
	}
}

void	wait_start(long long start_time)
{
	long long	delta;

	delta = start_time - get_time();
	if (delta > 0)
		usleep(delta * 1000);
}
