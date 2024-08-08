/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:38:57 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/17 10:43:41 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "utils_philo_bonus.h"

void	philo_eat(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	take_forks(philo);
	philo->last_eat = get_time(MILLISECONDS);
	monitoring(philo);
	print_status(philo, "EATING");
	step_by_step(philo, data->eat_time);
	philo->eat_count++;
	drop_forks(philo);
}

void	take_forks(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	sem_wait(data->forks);
	sem_wait(data->forks);
	print_status(philo, "TAKE A FORK");
	print_status(philo, "TAKE A FORK");
}

void	drop_forks(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	sem_post(data->forks);
	sem_post(data->forks);
	(void)philo;
}

void	philo_sleep(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	print_status(philo, "SLEEPING");
	monitoring(philo);
	step_by_step(philo, data->sleep_time);
}

void	philo_think(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	print_status(philo, "THINKING");
	monitoring(philo);
	step_by_step(philo, 1);
	while (*(int *)(data->forks) < 2)
		monitoring(philo);
}
