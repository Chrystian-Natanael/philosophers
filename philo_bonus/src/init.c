/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:49:03 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/17 10:44:39 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "utils_philo_bonus.h"

static void	philo_valid_input(const char *str_arg);

int	init_data(t_data *data, int argc, char **argv)
{
	validate_args(argc, argv);
	if (argc < 5 || argc > 6)
		return (u_error("Invalid number of arguments\n", 1));
	unlink_semaphores();
	data->num_of_philo = u_atol(argv[1]);
	data->death_time = u_atol(argv[2]) * 1e3;
	data->eat_time = u_atol(argv[3]) * 1e3;
	data->sleep_time = u_atol(argv[4]) * 1e3;
	if (argc == 6)
		data->limit_meal = u_atol(argv[5]);
	else
		data->limit_meal = -1;
	if (data->num_of_philo < 1 || data->num_of_philo > 200
		|| data->death_time < 0 || data->eat_time < 0
		|| data->sleep_time < 0 || (argc == 6 && data->limit_meal < 1))
		return (u_error("Invalid arguments\n", 1));
	data->philos = allocate(sizeof(t_philo) * data->num_of_philo);
	data->print = sem_open("/print", O_CREAT | O_RDWR, 0644, 1);
	data->forks = sem_open("/forks", O_CREAT | O_RDWR, 0644, \
	data->num_of_philo);
	return (0);
}

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

void	init_philos(t_data *data)
{
	struct timeval	time;
	int				i;

	gettimeofday(&time, NULL);
	data->start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	i = -1;
	while (++i < data->num_of_philo)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid < 0)
			u_error("Fork failed\n", 1);
		else if (data->philos[i].pid == 0)
		{
			data->philos[i].philo_id = i + 1;
			data->philos[i].eat_count = 0;
			data->philos[i].last_eat = get_time(MILLISECONDS);
			philos_life(&data->philos[i]);
		}
	}
}
