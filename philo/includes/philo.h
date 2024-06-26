/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:21:19 by cnatanae          #+#    #+#             */
/*   Updated: 2024/06/26 11:38:48 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// For use printf
# include <stdio.h>

// For use u_int64_t and write
# include <unistd.h>

// For use pthread functions
# include <pthread.h>

// For use time functions
# include <sys/time.h>

// For user boolean type
# include <stdbool.h>

// For use malloc and free
# include <stdlib.h>

typedef struct s_data
{
	long	death_time;
	long	eat_time;
	long	sleep_time;
	long	start_time;
	long	num_of_eat;
	int		num_of_philo;
	int		dead;
	int		finish;
}			t_data;

void	validate_args(int argc);
int		init_data(t_data *data, int argc, char **argv);

#endif