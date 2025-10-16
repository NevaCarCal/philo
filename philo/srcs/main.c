/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:23:03 by ncarrera          #+#    #+#             */
/*   Updated: 2025/10/13 14:31:30 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sim_launch(t_data_philos *data)
{
	pthread_t	watcher_thread;
	int			i;

	i = 0;
	data->sim_time = get_time();
	while (i < data->phil_num)
	{
		data->philos[i].last_eat_time = data->sim_time;
		if (pthread_create(&data->philos[i].thread, NULL,
				&philo_routine, &data->philos[i]) != 0)
		{
			ft_printerr("Couldn't create philo's threads.\n");
			return (0);
		}
		i++;
	}
	if (pthread_create(&watcher_thread, NULL, &watcher_routine, data) != 0)
	{
		ft_printerr("Couldn't start up watcher thread.\n");
		return (0);
	}
	pthread_join(watcher_thread, NULL);
	return (1);
}

static void	wait_threads(t_data_philos *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data_philos	data;

	if (!init_checks(&data, argc, argv))
		return (EXIT_FAILURE);
	if (!init_data(&data))
		return (EXIT_FAILURE);
	if (!sim_launch(&data))
	{
		philo_cleanup(&data);
		return (EXIT_FAILURE);
	}
	wait_threads(&data);
	philo_cleanup(&data);
	return (0);
}
