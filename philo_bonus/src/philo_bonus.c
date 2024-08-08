/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:29:19 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/16 21:04:27 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "utils_philo_bonus.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = get_data();
	if (init_data(data, argc, argv))
		quit(1);
	init_philos(data);
	wait_philos(data);
	close_semaphores();
	unlink_semaphores();
	quit(0);
}

void	wait_philos(t_data *data)
{
	int		status;
	long	i;

	i = 0;
	status = EXIT_SUCCESS;
	while (i < data->num_of_philo)
	{
		waitpid(0, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
			break ;
		i++;
	}
	if (status != EXIT_SUCCESS)
	{
		i = 0;
		while (i < data->num_of_philo)
			kill(data->philos[i++].pid, SIGKILL);
	}
}
