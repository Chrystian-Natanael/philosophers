/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:19:03 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/15 18:46:53 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils_philo.h"

void	safe_handle_mutex(t_mtx *fork, t_mutex_action action)
{
	if (action == LOCK)
		handle_mutex_error(pthread_mutex_lock(fork), action);
	else if (action == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(fork), action);
	else if (action == INIT)
		handle_mutex_error(pthread_mutex_init(fork, NULL), action);
	else if (action == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(fork), action);
	else
		u_error("Invalid mutex opcode.", 1);
}

void	handle_mutex_error(int error, t_mutex_action action)
{
	if (!error)
		return ;
	if (error == EINVAL && (action == LOCK || action == UNLOCK))
		u_error("The value specified by mutex is invalid.", 1);
	else if (error == EINVAL && action == INIT)
		u_error("The value specified by attr is invalid.", 1);
	else if (error == EDEADLK)
		u_error("A deadlock would occur if the thread \
		blocked wating for the mutex.", 1);
	else if (error == EPERM)
		u_error("The current thread this not hold a lock on the mutex.", 1);
	else if (error == ENOMEM)
		u_error("The process canot allocate enough mommory to create another \
		mutex.", 1);
	else if (error == EBUSY)
		u_error("Mutex is locked.", 1);
}
