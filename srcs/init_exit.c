/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:53:13 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/22 02:17:20 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_phil_data(t_data_philos *data, int argc, char **argv)
{
	int	i;

	i = 1;
	data->philnum = ft_atoi(argv[i++]);
	data->dietime = ft_atoi(argv[i++]);
	data->eattime = ft_atoi(argv[i++]);
	data->sleeptime = ft_atoi(argv[i++]);
	if (argc == 6)
		data->maxeatnum = ft_atoi(argv[i]);
}

int	init_checks(t_data_philos *data, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 || argc != 6)
	{
		printf("Please input between 4 and 5 arguments.\n");
		return (0);
	}
	while (argv[i])
	{
		if (!ft_ispnumstr(argv[i]))
		{
			printf("One or more invalid arguments. \
				All arguments must be numerical.\n");
			return (0);
		}
	}
	init_phil_data(data, argc, argv);
	return (1);
}
