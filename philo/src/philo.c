/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:21:02 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/13 16:22:26 by cnatanae         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv))
		return (1);
	init_philo(&data);
	start_dinner(&data); //TODO
	// end_dinner(&data); //TODO
	return (0);
}
