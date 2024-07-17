/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:21:19 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/16 15:32:58 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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

# define RST	"\033[0m"		/* Reset to default color */
# define RED	"\033[1;31m"	/* Bold Red */
# define G		"\033[1;32m"	/* Bold Green */
# define Y		"\033[1;33m"	/* Bold Yellow */
# define B		"\033[1;34m"	/* Bold Blue */
# define M		"\033[1;35m"	/* Bold Magenta */
# define C		"\033[1;36m"	/* Bold Cyan */
# define W		"\033[1;37m"	/* Bold White */

typedef struct s_data	t_data;
typedef pthread_mutex_t	t_mtx;

typedef enum e_mutex_action
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}				t_mutex_action;

typedef enum e_philo_action
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_A_FIRST_FORK,
	TAKE_A_SECOND_FORK,
	DIED
}			t_philo_action;

typedef struct s_fork
{
	int		fork_id;
	t_mtx	mutex;
}			t_fork;

typedef struct s_philo
{
	int			id;
	bool		full;
	long		meal_count;
	long		last_meal;
	t_mtx		mutex_philo;
	t_fork		*first_fork;
	t_fork		*second_fork;
	t_data		*data;
	pthread_t	thread_id;
}				t_philo;

struct s_data
{
	int				num_of_philo;
	bool			end_simulation;
	bool			all_threads_is_ready;
	long			death_time;
	long			eat_time;
	long			sleep_time;
	long			limit_meal;
	long			start_time;
	long			num_of_threads_running;
	t_fork			*forks;
	t_philo			*philos;
	t_mtx			mutex_table;
	t_mtx			mutex_write;
	pthread_t		monitor;
};

// Validation
void	validate_args(int argc);

// Inits
int		init_data(t_data *data, int argc, char **argv);
void	init_philo(t_data *data);
void	set_philos(t_data *data);
void	assign_forks(int philo_pos, t_fork *forks, t_philo *philo);

// Mutex
void	safe_handle_mutex(t_mtx *fork, t_mutex_action action);
void	handle_mutex_error(int error, t_mutex_action action);

// Threads
void	handle_thread_error(int error, t_mutex_action action);
void	safe_handle_thread(pthread_t *thread, void *(*func)(void *), \
		void *data, t_mutex_action action);

// Dinner
void	start_dinner(t_data *data);

// getters && setters
bool	get_bool(t_mtx *mutex, bool *src);
bool	simulation_finished(t_data *data);
void	set_bool(t_mtx *mutex, bool value, bool *dest);
void	set_long(t_mtx *mutex, long value, long *dest);
long	get_long(t_mtx *mutex, long *src);
void	increase_long(t_mtx *mutex, long *var);

// Synchro
void	wait_all_threads(t_data *data);
void	unsync_philos(t_philo *philo);

// Routines
void	eat(t_philo *philo);
void	thinking(t_philo *philo, bool pre_simulation);
void	*lone_philo(void *data);
void	end_dinner(t_data *data);

// Monitor
bool	all_threads_is_running(t_mtx *mutex, long *thread, long philo_nbr);
void	*monitor_simulation(void *data);

#endif