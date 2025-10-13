/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_meal_watcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:57:02 by ncarrera          #+#    #+#             */
/*   Updated: 2025/10/13 11:27:22 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	meals_complete(t_data_philos *data)
{
	int	status;
	int	i;

	if (data->max_eat_num == -1)
		return (0);
	i = 0;
	status = 1;
	pthread_mutex_lock(&data->data_lock);
	while (i < data->phil_num)
	{
		if (data->philos[i].times_eaten < data->max_eat_num)
		{
			status = 0;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&data->data_lock);
	return (status);
}

static int	philo_dead(t_philos *philo)
{
	long long	time_since_eating;

	pthread_mutex_lock(&philo->data->data_lock);
	time_since_eating = e_time(philo->last_eat_time);
	if (time_since_eating > philo->data->die_time)
	{
		philo->data->death_signal = 1;
		pthread_mutex_unlock(&philo->data->data_lock);
		pthread_mutex_lock(&philo->data->queue_lock);
		printf("%lld %d died\n", e_time(philo->data->sim_time), philo->id);
		pthread_mutex_unlock(&philo->data->queue_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->data_lock);
	return (0);
}

void	*watcher_routine(void	*arg)
{
	t_data_philos	*data;
	int				i;

	data = (t_data_philos *)arg;
	while (1)
	{
		i = 0;
		if (meals_complete(data))
		{
			pthread_mutex_lock(&data->data_lock);
			data->death_signal = 1;
			pthread_mutex_unlock(&data->data_lock);
			break ;
		}
		while (i < data->phil_num)
		{
			if (philo_dead(&data->philos[i]))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
