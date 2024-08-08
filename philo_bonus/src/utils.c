/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:55:37 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/17 11:35:14 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "utils_philo_bonus.h"

void	print_status(t_philo *philo, char *msg)
{
	t_data	*data;
	long	time;

	data = get_data();
	time = get_time(MILLISECONDS) - data->start_time;
	sem_wait(data->print);
	printf(CYAN"%-4zu"YELLOW" %-2zu"RST" %-3s\n", time, philo->philo_id, msg);
	sem_post(data->print);
}

void	print_status_die(t_philo *philo, char *msg)
{
	t_data	*data;
	long	time;

	data = get_data();
	time = get_time(MILLISECONDS) - data->start_time;
	sem_wait(data->print);
	printf(RED"%-4zu %-2zu %-3s\n"RST, time, philo->philo_id, msg);
}

long	get_current_time(void)
{
	t_data			*data;
	struct timeval	time;
	long			current_time;

	data = get_data();
	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	current_time -= data->start_time;
	return (current_time);
}

void	step_by_step(t_philo *philo, long step)
{
	usleep(step);
	monitoring(philo);
}
