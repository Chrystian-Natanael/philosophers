/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:03:15 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/17 11:11:56 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils_philo.h"

void	safe_handle_thread(pthread_t *thread, void *(*func)(void *), \
	void *data, t_mutex_action action)
{
	if (action == CREATE)
		handle_thread_error(pthread_create(thread, NULL, func, data), action);
	else if (action == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), action);
	else
		u_error("Wrong action for thread handle", 1);
}

void	handle_thread_error(int error, t_mutex_action action)
{
	if (!error)
		return ;
	if (action == EAGAIN)
		u_error("No resources to create another thread.", 1);
	else if (error == EPERM)
		u_error("The caller does note have appropriate permission.", 1);
	if (error == EINVAL && action == CREATE)
		u_error("The value specified by attr is invalid.", 1);
	else if (error == EINVAL && action == JOIN)
		u_error("The value specified by thread not joinable.", 1);
	else if (error == ESRCH)
		u_error("No thread could be found corresponding to that specified by \
		the given thread ID.", 1);
	else if (error == EDEADLK)
		u_error("A deadlock was detected or the value of thread specifies the \
		calling thread.", 1);
}
