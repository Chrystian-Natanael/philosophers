/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:26:01 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/15 20:16:42 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils_philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	validate_args(argc, argv);
	data->num_of_philo = u_atol(argv[1]);
	data->death_time = u_atol(argv[2]) * 1e3;
	data->eat_time = u_atol(argv[3]) * 1e3;
	data->sleep_time = u_atol(argv[4]) * 1e3;
	data->end_simulation = false;
	data->all_threads_is_ready = false;
	data->num_of_threads_running = 0;
	if (argc == 6)
		data->limit_meal = u_atol(argv[5]);
	else
		data->limit_meal = -1;
	if (data->num_of_philo <= 0 || data->num_of_philo > 200
		|| data->death_time < 0 || data->eat_time < 0
		|| data->sleep_time < 0 || (argc == 6 && data->limit_meal < 1))
		return (u_error("Invalid arguments", 0));
	return (0);
}

void	init_philo(t_data *data)
{
	int	i;

	i = -1;
	data->philos = allocate(data->num_of_philo * sizeof(t_philo));
	safe_handle_mutex(&data->mutex_table, INIT);
	safe_handle_mutex(&data->mutex_write, INIT);
	data->forks = allocate(data->num_of_philo * sizeof(t_fork));
	while (++i < data->num_of_philo)
	{
		safe_handle_mutex(&data->forks[i].mutex, INIT);
		data->forks[i].fork_id = i;
	}
	set_philos(data);
}

void	set_philos(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->num_of_philo)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meal_count = 0;
		philo->data = data;
		safe_handle_mutex(&philo->mutex_philo, INIT);
		assign_forks(i, data->forks, philo);
	}
}

void	assign_forks(int philo_pos, t_fork *forks, t_philo *philo)
{
	int	philo_count;

	philo_count = philo->data->num_of_philo;
	if ((philo->id % 2) == 0)
	{
		philo->first_fork = &forks[(philo_pos + 1) % philo_count];
		philo->second_fork = &forks[philo_pos];
	}
	else
	{
		philo->first_fork = &forks[philo_pos];
		philo->second_fork = &forks[(philo_pos + 1) % philo_count];
	}
}
