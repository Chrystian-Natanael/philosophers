/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:21:02 by cnatanae          #+#    #+#             */
/*   Updated: 2024/06/26 11:39:02 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils_philo.h"

void	validate_args(int argc)
{
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
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->num_of_philo = u_atol(argv[1]);
	data->death_time = u_atol(argv[2]);
	data->eat_time = u_atol(argv[3]);
	data->sleep_time = u_atol(argv[4]);
	data->start_time = get_time();
	data->dead = 0;
	data->finish = 0;
	if (argc == 6)
		data->num_of_eat = u_atol(argv[5]);
	else
		data->num_of_eat = -1;
	if (data->num_of_philo <= 0 || data->num_of_philo > 200 || data->death_time < 0 || data->eat_time < 0
		|| data->sleep_time < 0 || (argc == 6 && data->num_of_eat < 1))
		return (u_error("Invalid arguments", NULL));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	validate_args(argc);
	if (init_data(&data, argc, argv))
		return (1);
	printf("[philo] num_of_philo: [%d]\n", data.num_of_philo);
	printf("[philo] death_time: [%ld]\n", data.death_time);
		printf("[philo] eat_time: [%ld]\n", data.eat_time);
	printf("[philo] sleep_time: [%ld]\n", data.sleep_time);
	if (argc == 6)
		printf("[philo] num_of_eat: [%ld]\n", data.num_of_eat);
	printf("[philo] start_time: [%ld]\n", data.start_time);
	return (0);
}
