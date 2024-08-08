/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:39:37 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/15 18:47:32 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils_philo.h"

void	wait_all_threads(t_data *data)
{
	while (!get_bool(&data->mutex_table, &data->all_threads_is_ready))
		;
}

bool	all_threads_is_running(t_mtx *mutex, long *thread, long philo_nbr)
{
	bool	running;

	running = false;
	safe_handle_mutex(mutex, LOCK);
	if (*thread == philo_nbr)
		running = true;
	safe_handle_mutex(mutex, UNLOCK);
	return (running);
}

void	unsync_philos(t_philo *philo)
{
	if (philo->data->num_of_philo % 2 == 0)
	{
		if (philo->id % 2 == 0)
			u_precise_usleep(3e4, philo->data);
	}
	else
	{
		if (philo->id % 2 == 0)
			thinking(philo, true);
	}
}
