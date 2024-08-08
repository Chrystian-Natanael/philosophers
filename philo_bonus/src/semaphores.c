/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:05:16 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/16 19:14:28 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "utils_philo_bonus.h"

void	unlink_semaphores(void)
{
	sem_unlink("/print");
	sem_unlink("/forks");
}

void	close_semaphores(void)
{
	t_data	*data;

	data = get_data();
	sem_close(data->print);
	sem_close(data->forks);
}
