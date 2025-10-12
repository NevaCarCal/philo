/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:12:34 by ncarrera          #+#    #+#             */
/*   Updated: 2025/10/12 14:56:18 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_sim_done(t_data_philos *data)
{
	int	check;

	pthread_mutex_lock(&data->data_lock);
	check = data->death_signal;
	pthread_mutex_unlock(&data->data_lock);
	return (check);
}

void	*philo_routine(void *arg)
{
	t_philos	*p;

	p = (t_philos *)arg;
	while (!is_sim_done(p->data))
	{
		lock_forks(p);
		pthread_mutex_lock(&p->data->data_lock);
		p->last_eat_time = get_time();
		printf("%lld %d is eating\n", e_time(p->data->sim_time), p->id);
		p->times_eaten++;
		pthread_mutex_unlock(&p->data->data_lock);
		precise_usleep(p->data->eat_time);
		unlock_forks(p);
		if (is_sim_done(p->data))
			break ;
		printf("%lld %d is sleeping\n", e_time(p->data->sim_time), p->id);
		precise_usleep(p->data->sleep_time);
		if (is_sim_done(p->data))
			break ;
		printf("%lld %d is thinking\n", e_time(p->data->sim_time), p->id);
	}
	return (NULL);
}

void	philo_cleanup(t_data_philos *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	free(data->philos);
}
