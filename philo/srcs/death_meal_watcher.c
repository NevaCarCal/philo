/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_meal_watcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:57:02 by ncarrera          #+#    #+#             */
/*   Updated: 2025/11/21 13:38:37 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	meals_complete(t_data_philos *data)
{
	int	i;

	i = 0;
	if (data->max_eat_num == -1)
		return (0);
	while (i < data->phil_num)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (data->philos[i].times_eaten < data->max_eat_num)
		{
			pthread_mutex_unlock(&data->philos[i].meal_lock);
			return (0);
		}
		pthread_mutex_unlock(&data->philos[i].meal_lock);
		i++;
	}
	return (1);
}

static int	philo_dead(t_philos *philo)
{
	long long	time_since_eating;

	pthread_mutex_lock(&philo->meal_lock);
	time_since_eating = e_time(philo->last_eat_time);
	pthread_mutex_unlock(&philo->meal_lock);
	if (time_since_eating > philo->data->die_time)
	{
		pthread_mutex_lock(&philo->data->queue_lock);
		pthread_mutex_lock(&philo->data->data_lock);
		philo->data->death_signal = 1;
		printf("%lld %d died\n", e_time(philo->data->sim_time), philo->id);
		pthread_mutex_unlock(&philo->data->data_lock);
		pthread_mutex_unlock(&philo->data->queue_lock);
		return (1);
	}
	return (0);
}

static int	philo_checker(t_data_philos *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
	{
		if (philo_dead(&data->philos[i]))
			return (1);
		i++;
	}
	return (0);
}

void	*watcher_routine(void	*arg)
{
	t_data_philos	*data;

	data = (t_data_philos *)arg;
	wait_start(data->start_time);
	usleep(80);
	while (1)
	{
		if (philo_checker(data))
			return (NULL);
		if (meals_complete(data))
		{
			pthread_mutex_lock(&data->data_lock);
			data->death_signal = 1;
			pthread_mutex_unlock(&data->data_lock);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}
