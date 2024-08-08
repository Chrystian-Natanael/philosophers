/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:42:49 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/09 19:31:50 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils_philo.h"

void	set_bool(t_mtx *mutex, bool value, bool *dest)
{
	safe_handle_mutex(mutex, LOCK);
	*dest = value;
	safe_handle_mutex(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *src)
{
	bool	value;

	safe_handle_mutex(mutex, LOCK);
	value = *src;
	safe_handle_mutex(mutex, UNLOCK);
	return (value);
}

void	set_long(t_mtx *mutex, long value, long *dest)
{
	safe_handle_mutex(mutex, LOCK);
	*dest = value;
	safe_handle_mutex(mutex, UNLOCK);
}

long	get_long(t_mtx *mutex, long *src)
{
	long	value;

	safe_handle_mutex(mutex, LOCK);
	value = *src;
	safe_handle_mutex(mutex, UNLOCK);
	return (value);
}

bool	simulation_finished(t_data *data)
{
	return (get_bool(&data->mutex_table, &data->end_simulation));
}
