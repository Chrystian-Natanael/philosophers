/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:11:14 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/17 10:43:02 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "utils_philo_bonus.h"

static bool	philo_died(t_philo *philo);

void	monitoring(t_philo *philo)
{
	int		status;
	bool	someone_died;
	bool	eat_enough;
	t_data	*data;

	data = get_data();
	status = EXIT_SUCCESS;
	someone_died = philo_died(philo);
	eat_enough = (philo->eat_count >= data->limit_meal);
	if (someone_died || (data->limit_meal != -1 && eat_enough))
	{
		if (someone_died)
		{
			print_status_die(philo, "DIED");
			status = EXIT_FAILURE;
		}
		close_semaphores();
		quit(status);
	}
}

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;
	t_data	*data;

	data = get_data();
	if (data->limit_meal == 1 && philo->eat_count == data->limit_meal)
		return (false);
	elapsed = get_time(MILLISECONDS) - philo->last_eat;
	t_to_die = data->death_time / 1e3;
	if (elapsed > t_to_die)
		return (true);
	return (false);
}
