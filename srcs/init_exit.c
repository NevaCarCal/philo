/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:53:13 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/22 00:06:18 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_checks(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 || argc != 6)
	{
		printf("Please input between 4 and 5 commands.\n");
		return (0);
	}
	while (argv[i])
	{
		if (!ft_isnumstr(argv[i]))
		{
			printf("One or more invalid arguments. \
				All arguments must be numerical.\n");
			return (0);
		}
	}
}
