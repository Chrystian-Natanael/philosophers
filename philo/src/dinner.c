/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:33:07 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/15 19:48:54 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils_philo.h"

void	*dinner_simulation(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	wait_all_threads(ph->data);
	set_long(&ph->mutex_philo, get_time(MILLISECONDS), &ph->last_meal);
	increase_long(&ph->data->mutex_table, &ph->data->num_of_threads_running);
	unsync_philos(philo);
	while (!simulation_finished(ph->data))
	{
		if (get_bool(&ph->mutex_philo, &ph->full))
			break ;
		eat(ph);
		write_status(SLEEPING, ph);
		u_precise_usleep(ph->data->sleep_time, ph->data);
		thinking(ph, false);
	}
	return (NULL);
}

void	start_dinner(t_data *data)
{
	int	i;

	i = -1;
	if (data->limit_meal == 0)
		return ;
	else if (data->num_of_philo == 1)
		safe_handle_thread(&data->philos[0].thread_id, lone_philo, \
		&data->philos[0], CREATE);
	else
	{
		while (++i < data->num_of_philo)
			safe_handle_thread(&data->philos[i].thread_id, dinner_simulation, \
			&data->philos[i], CREATE);
	}
	safe_handle_thread(&data->monitor, monitor_simulation, data, CREATE);
	data->start_time = get_time(MILLISECONDS);
	set_bool(&data->mutex_table, true, &data->all_threads_is_ready);
	i = -1;
	while (++i < data->num_of_philo)
		safe_handle_thread(&data->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&data->mutex_table, true, &data->end_simulation);
	safe_handle_thread(&data->monitor, NULL, NULL, JOIN);
}

void	*lone_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->data);
	set_long(&philo->mutex_philo, get_time(MILLISECONDS), &philo->last_meal);
	increase_long(&philo->data->mutex_table, \
	&philo->data->num_of_threads_running);
	write_status(TAKE_A_FIRST_FORK, philo);
	while (!simulation_finished(philo->data))
		usleep(200);
	return (NULL);
}
