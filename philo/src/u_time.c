/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_time.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:35:17 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/01 09:12:16 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_philo.h"

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (u_error("gettimeofday() failed\n", NULL));
	return ((long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

long	u_usleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() < start + time)
		usleep(100);
	return (0);
}
