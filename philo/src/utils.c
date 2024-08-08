/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:15:02 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/17 11:14:10 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils_philo.h"

void	write_status(t_philo_action action, t_philo *philo)
{
	long	elapsed;

	if (philo->full)
		return ;
	safe_handle_mutex(&philo->data->mutex_write, LOCK);
	elapsed = get_time(MILLISECONDS) - philo->data->start_time;
	if ((action == TAKE_A_FIRST_FORK || action == TAKE_A_SECOND_FORK)
		&& !simulation_finished(philo->data))
		printf(PURPLE"%-6ld "RST"%d has "PURPLE"taken a fork\n"RST, \
		elapsed, philo->id);
	else if (action == EATING && !simulation_finished(philo->data))
		printf(GREEN"%-6ld "RST"%d is "GREEN"eating\n"RST, elapsed, philo->id);
	else if (action == SLEEPING && !simulation_finished(philo->data))
		printf(BLUE"%-6ld" RST" %d is "BLUE"sleeping\n"RST, elapsed, philo->id);
	else if (action == THINKING && !simulation_finished(philo->data))
		printf(CYAN"%-6ld"RST" %d is "CYAN"thinking\n"RST, elapsed, philo->id);
	else if (action == DIED)
		printf(RED"%-6ld %d died\n"RST, elapsed, philo->id);
	safe_handle_mutex(&philo->data->mutex_write, UNLOCK);
}

void	increase_long(t_mtx *mutex, long *var)
{
	safe_handle_mutex(mutex, LOCK);
	(*var)++;
	safe_handle_mutex(mutex, UNLOCK);
}
