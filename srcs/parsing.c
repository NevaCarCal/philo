/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:59:56 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/22 00:07:59 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	iof_check(long int num, int to_add, int sign)
{
	if (sign >= 0)
	{
		if (num > (INT_MAX - to_add) / 10)
			return (1);
		return (0);
	}
	else
	{
		if (num > ((long)INT_MIN * -1 - to_add) / 10)
			return (1);
		return (0);
	}
}

int	ft_isnumstr(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_safe_atoi(const char *nptr, int *status)
{
	long int	ctr;
	long int	sign;
	long int	result;

	sign = 1;
	ctr = 0;
	result = 0;
	while (ft_isspace(nptr[ctr]))
		ctr++;
	if (nptr[ctr] == '-' || nptr[ctr] == '+')
	{
		if (nptr[ctr] == '-')
			sign = -1;
		ctr++;
	}
	while (nptr[ctr] >= '0' && nptr[ctr] <= '9')
	{
		if (iof_check(result, (nptr[ctr] - '0'), sign))
			*status = -1;
		result = (result * 10) + (nptr[ctr] - '0');
		ctr++;
	}
	if (*status != 0)
		return (0);
	return ((int)(result * sign));
}
