/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_time.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:35:17 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/15 18:45:58 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_philo.h"

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

void	u_precise_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	rem;

	start = get_time(MICROSECONDS);
	while (get_time(MICROSECONDS) - start < usec)
	{
		if (simulation_finished(data))
			break ;
		elapsed = get_time(MICROSECONDS) - start;
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep(rem / 2);
		else
			while (get_time(MICROSECONDS) - start < usec)
				;
	}
}
