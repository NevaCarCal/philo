/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:23:03 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/22 02:18:23 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data_philos	data;

	if (!init_checks(&data, argc, argv))
		return (EXIT_FAILURE);
	printf("Hi\n");
}
