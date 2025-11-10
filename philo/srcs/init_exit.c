/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:53:13 by ncarrera          #+#    #+#             */
/*   Updated: 2025/11/10 12:19:28 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_phil_data(t_data_philos *data, int argc, char **argv)
{
	data->phil_num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->max_eat_num = ft_atoi(argv[5]);
		data->fed_phils = 0;
	}
	else
	{
		data->max_eat_num = -1;
		data->fed_phils = -1;
	}
}

static int	init_forks(t_data_philos *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->phil_num);
	if (data->forks == NULL)
	{
		ft_printerr("Couldn't allocate memory for forks.\n");
		return (0);
	}
	while (i < data->phil_num)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			ft_printerr("Couldn't initialize mutexes.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static void	init_philos(t_data_philos *data)
{
	int	i;

	i = 0;
	while (i < data->phil_num)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].times_eaten = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->phil_num];
		i++;
	}
}

int	init_checks(t_data_philos *data, int argc, char **argv)
{
	int	i;
	int	status;

	i = 1;
	status = 0;
	while (argv[i])
	{
		if (!ft_ispnumstr(argv[i]))
		{
			printf("Invalid characters in arguments.\n");
			return (0);
		}
		ft_safe_atoi(argv[i], &status);
		if (status != 0)
		{
			printf("Invalid numbers in arguments.\n");
			return (0);
		}
		i++;
	}
	init_phil_data(data, argc, argv);
	return (1);
}

int	init_data(t_data_philos *data)
{
	data->philos = malloc(sizeof(t_philos) * data->phil_num);
	if (data->philos == NULL)
	{
		ft_printerr("Couldn't allocate memory for the philosophers.\n");
		return (0);
	}
	if (pthread_mutex_init(&data->data_lock, NULL) != 0)
	{
		free(data->philos);
		return (0);
	}
	if (pthread_mutex_init(&data->queue_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->data_lock);
		free(data->philos);
		return (0);
	}
	data->death_signal = 0;
	if (!init_forks(data))
		return (0);
	init_philos(data);
	return (1);
}
