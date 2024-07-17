/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:21:19 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/17 10:45:54 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "garbage_collector.h"

// For use printf
# include <stdio.h>

// For use write
# include <unistd.h>

// For use pthread functions
# include <pthread.h>

// For use time functions
# include <sys/time.h>

// For user boolean type
# include <stdbool.h>

// For use malloc and free
# include <stdlib.h>

// For use INT_MAX and INT_MIN
# include <limits.h>

// For use errors mutex
# include <errno.h>

// For use semaphores
# include <semaphore.h>

// For use fork
# include <fcntl.h>

// For use SIGKILL
# include <signal.h>

// For use waitpid
# include <sys/wait.h>

# define RST	"\033[0m"		/* Reset to default color */
# define RED	"\033[1;31m"	/* Bold Red */
# define G		"\033[1;32m"	/* Bold Green */
# define Y		"\033[1;33m"	/* Bold Yellow */
# define B		"\033[1;34m"	/* Bold Blue */
# define M		"\033[1;35m"	/* Bold Magenta */
# define C		"\033[1;36m"	/* Bold Cyan */
# define W		"\033[1;37m"	/* Bold White */

typedef enum e_philo_action
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_A_FIRST_FORK,
	TAKE_A_SECOND_FORK,
	DIED
}			t_philo_action;

typedef struct s_data	t_data;

typedef struct s_philo
{
	pid_t	pid;
	long	philo_id;
	long	eat_count;
	long	last_eat;
}			t_philo;

struct s_data
{
	int		num_of_philo;
	long	death_time;
	long	eat_time;
	long	sleep_time;
	long	limit_meal;
	long	start_time;
	sem_t	*print;
	sem_t	*forks;
	t_philo	*philos;
};

// INIT
int		init_data(t_data *data, int argc, char **argv);
void	init_philos(t_data *data);

// VALIDATION
void	validate_args(int argc, char **argv);

// SEMAPHORES
void	unlink_semaphores(void);
void	close_semaphores(void);

// UTILS
t_data	*get_data(void);
void	print_status(t_philo *philo, char *msg);
long	get_current_time(void);
void	print_status_die(t_philo *philo, char *msg);

//PHILOS
void	philos_life(t_philo *philo);
void	monitoring(t_philo *philo);
void	wait_philos(t_data *data);

//ROUTINES
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	step_by_step(t_philo *philo, long step);

#endif