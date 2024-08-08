/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:18:40 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/17 10:43:48 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "utils_philo_bonus.h"

static void	philo_lonely(t_philo *philo);

void	philos_life(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	if (data->num_of_philo == 1)
		philo_lonely(philo);
	while (true)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

static void	philo_lonely(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	print_status(philo, "TAKE A FORK");
	usleep(data->death_time);
	print_status_die(philo, "DIED");
	close_semaphores();
	unlink_semaphores();
	quit(0);
}
