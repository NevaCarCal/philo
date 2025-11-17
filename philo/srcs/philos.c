/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:12:34 by ncarrera          #+#    #+#             */
/*   Updated: 2025/11/17 13:21:50 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lonely_philo(t_philos *p)
{
	print_queue(p, "has taken a fork");
	precise_usleep(p->data->die_time);
}

int	is_sim_done(t_data_philos *data)
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
	if (p->data->phil_num == 1)
	{
		lonely_philo(p);
		return (NULL);
	}
	if (p->id % 2 == 0)
		precise_usleep(1);
	while (!is_sim_done(p->data))
	{
		lock_forks(p);
		print_queue(p, "is eating");
		pthread_mutex_lock(&p->meal_lock);
		p->last_eat_time = get_time();
		p->times_eaten++;
		pthread_mutex_unlock(&p->meal_lock);
		philo_sleep(p->data->eat_time, p->data);
		unlock_forks(p);
		print_queue(p, "is sleeping");
		philo_sleep(p->data->sleep_time, p->data);
		print_queue(p, "is thinking");
	}
	return (NULL);
}

void	philo_cleanup(t_data_philos *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
	{
		pthread_mutex_destroy(&data->philos[i].meal_lock);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->data_lock);
	pthread_mutex_destroy(&data->queue_lock);
	free(data->forks);
	free(data->philos);
}

void	print_queue(t_philos *philo, const char *msg)
{
	pthread_mutex_lock(&philo->data->data_lock);
	if (philo->data->death_signal == 1)
	{
		pthread_mutex_unlock(&philo->data->data_lock);
		return ;
	}
	pthread_mutex_lock(&philo->data->queue_lock);
	printf("%lld %d %s\n", e_time(philo->data->sim_time), philo->id, msg);
	pthread_mutex_unlock(&philo->data->queue_lock);
	pthread_mutex_unlock(&philo->data->data_lock);
}
