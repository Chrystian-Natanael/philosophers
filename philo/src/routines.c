/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:14:19 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/15 19:49:11 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils_philo.h"

void	eat(t_philo *philo)
{
	safe_handle_mutex(&philo->first_fork->mutex, LOCK);
	write_status(TAKE_A_FIRST_FORK, philo);
	safe_handle_mutex(&philo->second_fork->mutex, LOCK);
	write_status(TAKE_A_SECOND_FORK, philo);
	set_long(&philo->mutex_philo, get_time(MILLISECONDS), &philo->last_meal);
	philo->meal_count++;
	write_status(EATING, philo);
	u_precise_usleep(philo->data->eat_time, philo->data);
	if (philo->data->limit_meal > 0
		&& philo->meal_count == philo->data->limit_meal)
		set_bool(&philo->mutex_philo, true, &philo->full);
	safe_handle_mutex(&philo->first_fork->mutex, UNLOCK);
	safe_handle_mutex(&philo->second_fork->mutex, UNLOCK);
}

void	thinking(t_philo *philo, bool pre_simulation)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!pre_simulation)
		write_status(THINKING, philo);
	if (philo->data->num_of_philo % 2 == 0)
		return ;
	t_eat = philo->data->eat_time;
	t_sleep = philo->data->sleep_time;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	u_precise_usleep(t_think * 0.42, philo->data);
}
