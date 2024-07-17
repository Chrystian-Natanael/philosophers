/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:21:02 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/17 10:36:22 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils_philo.h"

static void	philo_valid_input(const char *str_arg);

void	validate_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Philosophers: Invalid number of arguments\n");
		printf("Try: \n");
		printf("./philo \033[92m[1] [2] [3] [4] [5]\033[0m\n");
		printf("\033[92m[1]\033[0m - Number of philosophers\n");
		printf("\033[92m[2]\033[0m - Time to die\n");
		printf("\033[92m[3]\033[0m - Time to eat\n");
		printf("\033[92m[4]\033[0m - Time to sleep\n");
		printf("\033[92m[5]\033[0m - Num of times each philo must eat - Opt\n");
		exit(1);
	}
	i = 0;
	while (++i < argc)
		philo_valid_input(argv[i]);
}

static void	philo_valid_input(const char *str_arg)
{
	while (*str_arg)
	{
		if (*str_arg < '0' || *str_arg > '9')
			u_error("Invalid argument. Only positives numbers are allowed.", 1);
		str_arg++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv))
		return (1);
	init_philo(&data);
	start_dinner(&data);
	end_dinner(&data);
	quit (0);
}

void	end_dinner(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
		safe_handle_mutex(&data->forks[i].mutex, DESTROY);
	safe_handle_mutex(&data->mutex_table, DESTROY);
	safe_handle_mutex(&data->mutex_write, DESTROY);
}
