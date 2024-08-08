/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:08:14 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/15 19:48:58 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils_philo.h"

static bool	philo_died(t_philo *philo);

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo->mutex_philo, &philo->full))
		return (false);
	elapsed = get_time(MILLISECONDS) - get_long(&philo->mutex_philo, \
	&philo->last_meal);
	t_to_die = philo->data->death_time / 1e3;
	if (elapsed > t_to_die)
		return (true);
	return (false);
}

void	*monitor_simulation(void *data)
{
	int		i;
	t_data	*data_ph;

	data_ph = (t_data *)data;
	while (!all_threads_is_running(&data_ph->mutex_table, \
		&data_ph->num_of_threads_running, data_ph->num_of_philo))
		;
	while (!simulation_finished(data_ph))
	{
		i = -1;
		while (++i < data_ph->num_of_philo
			&& !simulation_finished(data_ph))
		{
			if (philo_died(data_ph->philos + i))
			{
				set_bool(&data_ph->mutex_table, true, &data_ph->end_simulation);
				write_status(DIED, data_ph->philos + i);
			}
		}
	}
	return (NULL);
}
