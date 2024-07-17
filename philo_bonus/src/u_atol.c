/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_atol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:39:03 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/16 15:39:18 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_philo_bonus.h"

bool	is_in_strings(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

long	u_atol(const char *str)
{
	int		sign;
	long	result;

	while (is_in_strings(*(char *) str, "\t\n\v\f\r "))
		str++;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (result * 10 < 0)
			return (-1);
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}
