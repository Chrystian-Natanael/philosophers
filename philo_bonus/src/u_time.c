/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_time.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:37:44 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/16 15:38:03 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_philo_bonus.h"

long	get_time(t_time_code code)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (u_error("gettimeofday() failed\n", 0));
	if (code == SECONDS)
		return (time.tv_sec + (time.tv_usec / 1e6));
	else if (code == MILLISECONDS)
		return ((time.tv_sec * 1e3) + (time.tv_usec / 1e3));
	else if (code == MICROSECONDS)
		return ((time.tv_sec * 1e6) + time.tv_usec);
	else
		u_error("Invalid time code\n", 0);
	return (1337);
}
